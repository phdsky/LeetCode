/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 *
 * https://leetcode.cn/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (61.85%)
 * Likes:    413
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 47.3K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * 给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个非空子数组，且数组内部是连续的 。 分数
 * 由每个子数组内的平均值的总和构成。
 *
 * 注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。
 *
 * 返回我们所能得到的最大 分数 是多少。答案误差在 10^-6 内被视为是正确的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [9,1,2,3,9], k = 3
 * 输出: 20.00000
 * 解释:
 * nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
 * 我们也可以把 nums 分成[9, 1], [2], [3, 9].
 * 这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7], k = 4
 * 输出: 20.50000
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start

/**
 * 动态规划 + 前缀和优化
 * dp[i][k] 表示：将 nums 中的前 i 个数分成 k 个子数组的最大平均值总和
 * 递推方程：
 * dp[i][1] = (nums[0] + ... + nums[i - 1]) / i
 * dp[i][k] = max(dp[i][k], dp[j][k - 1] + avg[j][i])
 */
class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<double> prefix(n + 1, 0);
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            dp[i][1] = prefix[i] / i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int l = 2; l <= k; l++)
            {
                for (int j = 1; j < i; j++)
                {
                    double avg = (prefix[i] - prefix[j]) / (i - j);
                    dp[i][l] = max(dp[i][l], dp[j][l - 1] + avg);
                }
            }
        }

        return dp[n][k];
    }
};
// @lc code=end
