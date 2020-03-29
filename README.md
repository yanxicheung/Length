# OOBC:Length

## 需求一：

实现一个库，通过这个库，用户可以以Mile为单位来表示一个长度，精度为1Mile，并且，可以对比两个长度的相等性：

- 3Mile == 3Mile

- 3Mile != 2Mile

- 3Mile != 4Mile

### 设计考虑：

#### 消除知识重复：

  ```c++
bool Mile::operator ==(const Mile& rhs)
  {
      return this->amount == rhs.amount;
  }
  
  bool Mile::operator !=(const Mile& rhs)
  {
      return not this->operator ==(rhs);
  }
  ```

  #### 抽象：

  ```c++
using Amount = unsigned int;
  ```

  让客户不再依赖具体的类型，而是提供一个抽像，只是抽象的背后的本质仍然是`unsigned int`。

  数量现在已经由一个抽象数据类型`Amount`来表示。别名技术可以解决它变化的问题。不过，以`double`来表示数量就完全没有可能是一个类吗？`double` 的精度控制问题难道不是`Amount`的职责吗？

  既然`Amount`向类变化的可能性是存在的，那么我们就需要考虑：如果它变成类，我们需要付出什么样的代价来应对它？

  我们似乎无须为之做任何事情，即使`Amount`是一个类，但既然它本质上应该是一个数值，那么它就应该支持所有的数值计算。       

## 需求二：

用户除了可以使用Mile为单位来表示长度外，还可以使用Yard为单位来表示长度，其中：

- 当以Mile为单位表示一个长度时，精度为1 Mile;
- 当以Yard为单位表示一个长度时，精度为1Yard;
- 能够对比任意两个长度的相等性：
     - 1Mile == 1760Yard
     - 3Yard == 3Yard
     - 1Mile != 1761Yard
     - 3Yard != 4Yard

重复，很多时候不仅仅是重复这么简单。其背后往往意味着重大的设计缺陷，一些核心的本质概念没有被发现。

如果这样的重复得不到消除，未来的演进会越来越别扭。会进一步带来更强的耦合，快速增长的工作量，更加难以理解的设计和实现，更多出现bug的机会。

### 设计考虑：

#### 提取基类：

```c++
struct Length
{
    bool operator==(const Length&rhs) const;
    bool operator!=(const Length&rhs) const;
protected:
    Length(const Amount &amountInBaseUnit);
private:
    Amount amountInBaseUnit;
};
```

通过提取基类来消除代码重复。我们将Length的构造函数设置为`protected`的，Why？

因为按照需求，以及我们当前的设计，既然存在`Mile`和`Yard`等具体可以用来表现长度的对象，所以我们不希望用户直接使用我们为了消除重复而抽取出来的基类来构造长度对象。

至于`Yard `和 `Mile`的实现只需要将各自的`amount`转换成`Length`要求的基本单位即可。



#### 提高表现力：

```c++
const unsigned int YARDS_PER_MILE = 1760;
Mile::Mile(const Amount& amount):Length(amount*YARDS_PER_MILE)
{

}
```

1760是一个magic number，应该定义一个常量使其语义更加明确。



#### 消除冗余：

目前对于`Mile`和`Yard`他们的唯一职责就是将自己的单位转换成基准单位，`Mile`和`Yard`的实现仅仅是转换系数的不同：

```c++
Mile::Mile(const Amount& amount):Length(amount*YARDS_PER_MILE){}
Yard::Yard(const Amount& amount):Length(amount*YARDS_PER_YARD){}
```

我们可以将这个实现转换成`Length`的一个构造函数。这样**将单位转换成基准单位**的这个职责现在由基类`Length`承担。

```c++
Length::Length(const Amount& amount, unsigned int conversionFactor):
amountInBaseUnit(amount*conversionFactor)
{
}
```

至此`Mile`和`Yard`不再承担任何职责，可以将他们删除了。



#### 提高UI表现力：

现在我们将UI定义为：

```c++
ASSERT_TRUE(Length(3,YARDS_PER_YARD) == Length(3,YARDS_PER_YARD));
ASSERT_TRUE(Length(1,YARDS_PER_MILE) == Length(1760,YARDS_PER_YARD));
ASSERT_TRUE(Length(1760,YARDS_PER_YARD) == Length(1,YARDS_PER_MILE));
```

简单阅读下用例，会发现这个UI存在如下问题：

- 用户需要知道策略是向`Yard`转换的
- `Length(3,YARDS_PER_YARD)`不容易理解

前者增加了不必要的**耦合**，后者造成了**糟糕的表现力**。

解决耦合问题，我们可以使用正交设计原则的一个策略：**向着稳定的方向依赖** ，什么稳定？一个更加抽象的名字，而不是与实现细节有关的更加具体，更不稳定的名字。

当然一个好的名字，会更有表现力。

所以，如果我们将转换系数定义为更有表现力的常量，上述问题将迎刃而解。

```c++
const unsigned int YARDS_PER_MILE = 1760;
const unsigned int YARDS_PER_YARD = 1;

const unsigned int MILE = YARDS_PER_MILE;
const unsigned int YARD = YARDS_PER_YARD;
```

用例调整为：

```c++
ASSERT_TRUE(Length(3,YARD) == Length(3,YARD));
ASSERT_TRUE(Length(1,MILE) == Length(1760,YARD));
ASSERT_TRUE(Length(1760,YARD) == Length(1,MILE));
```



## 需求三：

增加两个新的单位，Feet和Inch，用户可以使用他们作为单位来表现一个长度。其中：

- 1 Yard == 3 Feet
- 1 Feet == 12 Inch
- 当以Feet为单位来表达长度单位时，精度为1 Feet
- 当以Inch为单位来表达长度单位时，精度为1 Inch

### 设计考虑：

#### 准确命名：

现在，我们来看看这些常量的定义，会发现：每个常量都定义了一个单位向基准单位转换的转换系数，但是其名字却与转换系数没有任何关系：

```c++
const unsigned int BASE_UNIT = 1;
const unsigned int BASE_PER_INCH = BASE_UNIT;
const unsigned int BASE_PER_FEET = 12 * BASE_PER_INCH;
const unsigned int BASE_PER_YARD = 3 * BASE_PER_FEET;
const unsigned int BASE_PER_MILE = 1760 * BASE_PER_YARD;
```

这会让读者感到困惑，这种不直观背后隐藏着由于设计方式带来的**隐性知识**，为了消除这种困惑，我们需要把知识**显性化**：让命名更加准确：

```c++
const unsigned int BASE_CONV_FACTOR = 1;
const unsigned int INCH_CONV_FACTOR = BASE_CONV_FACTOR;
const unsigned int FEET_CONV_FACTOR = 12 * INCH_CONV_FACTOR;
const unsigned int YARD_CONV_FACTOR = 3 * FEET_CONV_FACTOR;
const unsigned int MILE_CONV_FACTOR = 1760 * YARD_CONV_FACTOR;
```

#### 以类取代类型码：

从UI的角度来看，`YARD`代表的是一个长度单位，但是`Length`的第二个参数在实现上却是一个转换系数。这是一种矛盾，是由于**问题域和设计域没有实现无缝对接** 。

```c++
ASSERT_TRUE(Length(3,YARD) != Length(4,YARD));
```

那如何将用户关注的**长度单位**这个概念与实现所需要的**转换系数**联系在一起呢？？

在OO范式下，我们很容易想到类：增加一个用来代表长度单位概念的类，再把转换系数当作类的内部实现隐藏起来，就可以将两个概念联系在一起了。

代码实现为：

```c++
/////////////////LengthUnit.h////////////////////
struct LengthUnit
{
    explicit LengthUnit(unsigned int conversionFactor);
    unsigned int getConversionFactor() const;
private:
    unsigned int conversionFactor;
};

static LengthUnit MILE(MILE_CONV_FACTOR);
static LengthUnit YARD(YARD_CONV_FACTOR);
static LengthUnit FEET(FEET_CONV_FACTOR);
static LengthUnit INCH(INCH_CONV_FACTOR);
/////////////////Length.cpp///////////////////////
bool Length::operator ==(const Length& rhs) const
{
    return this->amountInBaseUnit == rhs.amountInBaseUnit;
}

bool Length::operator !=(const Length& rhs) const
{
    return not this->operator ==(rhs);
}

Length::Length(const Amount& amount, const LengthUnit&unit):
amountInBaseUnit(amount*unit.getConversionFactor())
{
}
```

#### 依赖管理：

在`LengthUnit`中，我们看到了`Getter`方法，这是一种破坏封装的强烈的坏味道：

```c++
struct LengthUnit
{
    explicit LengthUnit(unsigned int conversionFactor);
    unsigned int getConversionFactor() const;
private:
    unsigned int conversionFactor;
};
```

之前使用这种方案是为了快速重构，在管理学中分析问题时，经常采用**5 Why** 分析法，通过不断问问题找到问题发生的根源。我们采用这种方式：

1. Q：`Length`为什么需要`LengthUnit`提供`Getter`来获得转换系数？

   A：因为`Length`需要使用这个转换系数，将原有单位转换为基准单位。

2. Q: 既然`Length`真正需要的是**转换**这件事，为什么不让`LengthUnit`来提供这个服务，却要自己来通过`Getter`来获得转换系数，然后自己来做转换呢？？

   A: **Sounds Good...**

3. 结论：向稳定方向依赖，让`Length`来依赖一个更具本质的需要：**转换** ,相对于依赖**转换系数**这个细节，其更加稳定。



## 需求四：

要求用户只能使用既有的单位(`Mile`,`Yard`,`Feet`,`Inch`)，而不该有能力创建新的单位；避免用户由于某些原因创建一些不存在的单位，从而让系统变得令人难以理解。

### 设计考虑：

#### Slug：

这是一个非功能需求，不允许用户创建额外的`LengthUnit`对象。这样的需求，在使用C++来实现的范式时，让`LengthUnit` 的构造函数变为私有，这样在`LengthUnit`的外部，就无法创建任何`LengthUnit`对象，即使是通过继承也不行。

```c++
struct LengthUnit
{
    unsigned int getAmountInBaseUnit(const Amount&amount) const;
    static const LengthUnit & getMile();
    static const LengthUnit & getYard();
    static const LengthUnit & getFeet();
    static const LengthUnit & getInch();
private:
    explicit LengthUnit(unsigned int conversionFactor);
private:
    unsigned int conversionFactor;
};

#define MILE   (LengthUnit::getMile())
#define YARD   (LengthUnit::getYard())
#define FEET   (LengthUnit::getFeet())
#define INCH   (LengthUnit::getInch())
```

处理这类问题的方法，被称为Slug模式。

#### 消除重复：

可以看出，上述代码有着强烈的重复模式：除了名字差别，各个`Unit`的定义是完全一样的。宏的标识符的链接功能则是解决这类问题的灵丹妙药。



## 需求五：

任意两个长度 可以进行加法运算：

- `13 Inch + 11 Inch  = 2 Feet`
- `3 Feet + 2 Yard = 3 Yard`

### 设计考虑：

#### 知识重复：

仔细审视，当前代码似乎没有什么重复，但是如果仔细审视，就会发现一个`Bad Smell`。在加法实现的最后一行有这样一个表达式：`Length(amount,INCH)`

`Length`的第二个参数，使用了当前基准单位：`INCH`;

**INCH是Length的当前基准单位**是当前系统的一项知识，系统中有两个地方对这个知识进行了直接描述：

```c++
///////Length.cpp//////
Length Length::operator +(const Length& rhs)
{
    Amount amount = this->amountInBaseUnit + rhs.amountInBaseUnit;
    return Length(amount,INCH);
}
///////LengthUnit.cpp//////
DEF_CONV_FACTOR(Inch, =, 1, BASE)
```

二者都依赖了这个知识，当这个只是发生变化的时候，`LengthUnit`和`Length`都需要进行修改，所以这是一种重复。

按照`DRY`原则，这个知识只应该存在一个明确而权威的表示：

很明显，`LengthUnit`应该是这个知识的唯一描述，加法运算需要的是**当前基准单位**这个抽象概念，而不是**INCH作为当前基准长度单位**这个不稳定的知识。

向着稳定的方向依赖，`Length`应当依赖于`LengthUnit`提供的**当前基准长度单位**这个概念。如下：

```c++
///////Length.cpp////////
Length Length::operator +(const Length& rhs)
{
    Amount amount = this->amountInBaseUnit + rhs.amountInBaseUnit;
    return Length(amount,LengthUnit::getBaseUnit());
}

///////LengthUnit.cpp//////
const LengthUnit& LengthUnit::getBaseUnit()
{
    return getInch();
}
```



## 需求六：

实现一个容量(Volume)库。通过这个库,用户可以使用TSP (茶匙),TBSP (汤匙),OZ (盎司)为单位来表示一个容量。其中：

-  1 TBSP = 3 TSP
-  1 OZ = 2 TBSP
-  当以TBSP为单位来表示一个容量时,精度为1 TBSP
-  当以TSP为单位来表示一个容量时,精度为1 TSP
-  当以OZ为单位来表示一个容量时,精度为1 OZ
-  可以对比任意两个容量的相等性
-  只允许用户使用现有的三个容量单位来表示容量
-  两个容量可以相加