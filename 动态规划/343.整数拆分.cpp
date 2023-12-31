/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (61.54%)
 * Likes:    781
 * Dislikes: 0
 * Total Accepted:    153.9K
 * Total Submissions: 250K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 *
 * 返回 你可以获得的最大乘积 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 *
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   递推公式 dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j)) 解释如下：

   对于整数 i，每次可以分解为 (i - j) 和 j 两部分；此时 (i - j) 可以选择是否再继续分解，即是否为 (i - j) 或 dp[i - j].
*/
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }

        return dp[n];
    }
};
// @lc code=end
