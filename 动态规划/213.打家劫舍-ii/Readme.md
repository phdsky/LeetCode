### 213.打家劫舍-ii

1. 动态规划
   
   分两种情况计算递推矩阵： 1. 选择第0个，则不能选择最后一个；2. 不选择第0个，则可以选择最后一个。

   最后比较两种情况下的最大值即可。
   
[Leetcode Link](https://leetcode-cn.com/problems/house-robber-ii/)