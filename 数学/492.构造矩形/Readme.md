### 492.构造矩形

基本思路：

最理想的构造方法即为面积可开方，此时长宽值一致；因此只要宽度从开方值从大到小遍历，面积可整除宽度即可得到长度，此时宽度长度差也是最小的。

[Leetcode Link](https://leetcode-cn.com/problems/construct-the-rectangle/)