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



## 需求三：

增加两个新的单位，Feet和Inch，用户可以使用他们作为单位来表现一个长度。其中：

- 1 Yard == 3Feet
- 1 Feet == 12 Inch
- 当以Feet为单位来表达长度单位时，精度为1 Feet
- 当以Inch为单位来表达长度单位时，精度为1 Inch