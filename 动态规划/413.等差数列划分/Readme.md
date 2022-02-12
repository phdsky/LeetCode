### 413.等差数列划分

1. 动态规划
   
   先计算数列的前后差数组，至少连续两个相等的差表示一个最小(3)等差数列，且差值的个数N可构成 N*(N - 1) / 2个等差数列

   从前往后遍历累加即可
   
[Leetcode Link](https://leetcode-cn.com/problems/arithmetic-slices/)