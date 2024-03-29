/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 *
 * https://leetcode-cn.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    532
 * Dislikes: 0
 * Total Accepted:    84.3K
 * Total Submissions: 194.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
 *
 * 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回
 * true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,4,5]
 * 输出：true
 * 解释：任何 i < j < k 的三元组都满足题意
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,4,3,2,1]
 * 输出：false
 * 解释：不存在满足题意的三元组
 *
 * 示例 3：
 *
 *
 * 输入：nums = [2,1,5,0,4,6]
 * 输出：true
 * 解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 * 进阶：你能实现时间复杂度为 O(n) ，空间复杂度为 O(1) 的解决方案吗？
 *
 */

// @lc code=start

/**
 * a 始终记录最小元素，b 为某个子序列里第二大的数。
   接下来不断更新 a，同时保持 b 尽可能的小。
   如果下一个元素比 b 大，说明找到了三元组。
*/
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int size = nums.size();
        if (size < 3)
        {
            return false;
        }

        int a = INT_MAX;
        int b = INT_MAX;
        for (const auto &n : nums)
        {
            if (n <= a)
            {
                a = n;
            }
            else if (n <= b)
            {
                b = n;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
