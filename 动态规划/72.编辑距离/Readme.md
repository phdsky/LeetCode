### 72.编辑距离

1. 动态规划
   
   - 状态定义：

      dp[i][j]表示word1的前i个字母转换成word2的前j个字母所使用的最少操作。

   - 状态转移：

      i指向word1，j指向word2,若当前字母相同，则:
      
      $dp[i][j] = dp[i - 1][j - 1]$

      否则取插入、删除、替换三个操作的最小值 + 1， 即:
      
      $dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1$


      其中：
      - dp[i - 1][j]表示删除操作，即0～i-1的word1通过某些操作可以得到0～j的word2，那么删除word1的i位置字符串再进行同样操作即可
         
      - dp[i][j - 1]表示插入操作，即0～i的word1通过某些操作可以得到0～j-1的word2，那么直接在word1中直接插入word2的j位置字符即可
         
      - dp[i - 1][j - 1]表示替换操作，即0～i-1的word1已经可以得到0~j-1的word2，此时分为i，j字符相等和不等两种情况，不等则需要经过一次替换

   
[Leetcode Link](https://leetcode-cn.com/problems/edit-distance/)