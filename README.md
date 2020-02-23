# OOBC:Length

## 需求一：

实现一个库，通过这个库，用户可以以Mile为单位来表示一个长度，精度为1Mile，并且，可以对比两个长度的相等性：

- 3Mile == 3Mile

- 3Mile != 2Mile

- 3Mile != 4Mile

  

## 需求二：

用户除了可以使用Mile为单位来表示长度外，还可以使用Yard为单位来表示长度，其中：

- 当以Mile为单位表示一个长度时，精度为1 Mile;

- 当以Yard为单位表示一个长度时，精度为1Yard;

- 能够对比任意两个长度的相等性：

     - 1Mile == 1760Yard

     - 3Yard == 3Yard

     - 1Mile != 1761Yard

     - 3Yard != 4Yard

       

## 需求三：

增加两个新的单位，Feet和Inch，用户可以使用他们作为单位来表现一个长度。其中：

- 1 Yard == 3Feet
- 1 Feet == 12 Inch
- 当以Feet为单位来表达长度单位时，精度为1 Feet
- 当以Inch为单位来表达长度单位时，精度为1 Inch