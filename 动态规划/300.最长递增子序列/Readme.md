### 300.最长递增子序列

1. 动态规划
   
   dp[i] 表示当前 nums[i] 数字中最长递增长度
   
   每次当数字长度 nums[i] > nums[i - 1] 增加时，更新 dp[i]
   
[Leetcode Link](https://leetcode-cn.com/problems/longest-increasing-subsequence/)