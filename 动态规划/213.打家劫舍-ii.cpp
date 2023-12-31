/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (43.56%)
 * Likes:    987
 * Dislikes: 0
 * Total Accepted:    227.9K
 * Total Submissions: 523K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   分两种情况计算递推矩阵： 1. 选择第0个，则不能选择最后一个；2. 不选择第0个，则可以选择最后一个。

   最后比较两种情况下的最大值即可。
*/
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        else if (n == 2)
        {
            return max(nums[0], nums[1]);
        }

        // 0 selected
        vector<vector<int>> dpS(n, vector<int>(2, 0));
        dpS[1][0] = nums[0];
        dpS[1][1] = nums[0];
        for (int i = 2; i < n - 1; i++)
        {
            dpS[i][0] = max(dpS[i - 1][0], dpS[i - 1][1]);
            dpS[i][1] = dpS[i - 1][0] + nums[i];
        }

        // 0 not selected
        vector<vector<int>> dpN(n, vector<int>(2, 0));
        for (int i = 1; i < n; i++)
        {
            dpN[i][0] = max(dpN[i - 1][0], dpN[i - 1][1]);
            dpN[i][1] = dpN[i - 1][0] + nums[i];
        }

        int maxS = max(dpS[n - 2][0], dpS[n - 2][1]);
        int maxN = max(dpN[n - 1][0], dpN[n - 1][1]);

        return max(maxS, maxN);
    }
};
// @lc code=end
