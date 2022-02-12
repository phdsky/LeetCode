### 322.零钱兑换

1. 动态规划 
   
   递推公式 dp[i] = min(dp[i], dp[i - coins[j]] + 1) 解释如下：
   
   例如 coins = [1, 2, 5], amount = 11，此测试样例中：
    
   dp[11] = min(dp[11], dp[6] + 1) / min(dp[11], dp[9] + 1) / min(dp[11], dp[10] + 1) 可选择为三者值之一
            
   
[Leetcode Link](https://leetcode-cn.com/problems/coin-change/)