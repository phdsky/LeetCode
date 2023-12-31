/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.89%)
 * Likes:    585
 * Dislikes: 0
 * Total Accepted:    59.8K
 * Total Submissions: 136.1K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 *
 * 注意 这个数列必须是 严格 递增的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 *
 *
 * 示例 2:
 *
 *
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 *
 *
 *
 *
 * 提示: 
 *
 *
 *
 *
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   dp[i] 表示当前 nums[i] 数字中最长递增长度

   每次当数字长度 nums[i] > nums[i - 1] 增加时，更新 dp[i]；

   同时用cnt记录当前最大长度子序列的个数

[Leetcode Link](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)

此题为 [300.最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence) 的进阶版。
*/
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> dp(size, 0);
        vector<int> cnt(size, 0);

        int maxlen = 0, res = 0;
        for (int i = 0; i < size; i++)
        {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++)
            {
                // 当前数字大于前面的数字
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    // 说明有相同长度子串
                    else if (dp[j] + 1 == dp[i])
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
            // 序列变长
            if (dp[i] > maxlen)
            {
                maxlen = dp[i];
                res = cnt[i];
            }
            // 出现相同长度序列
            else if (dp[i] == maxlen)
            {
                res += cnt[i];
            }
        }
        return res;
    }
};
// @lc code=end
