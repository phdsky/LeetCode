### 343.整数拆分

1. 动态规划
   
   递推公式 dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j)) 解释如下：

   对于整数 i，每次可以分解为 (i - j) 和 j 两部分；此时 (i - j) 可以选择是否再继续分解，即是否为 (i - j) 或 dp[i - j].

   
[Leetcode Link](https://leetcode-cn.com/problems/integer-break/)