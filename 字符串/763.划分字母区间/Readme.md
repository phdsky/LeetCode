### 763.划分字母区间

1. [贪心算法](https://leetcode-cn.com/problems/partition-labels/solution/hua-fen-zi-mu-qu-jian-by-leetcode-solution/)

   首先建立所有字符最后一次出现的位置；再次遍历时，只要当前下标和此时字符最大的max下标相等时，表示后面已经没有该字符了，此时即为一个最小区间。

[Leetcode Link](https://leetcode-cn.com/problems/partition-labels/)