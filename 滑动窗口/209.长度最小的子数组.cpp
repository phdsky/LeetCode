/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (48.22%)
 * Likes:    980
 * Dislikes: 0
 * Total Accepted:    268.2K
 * Total Submissions: 556.2K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * 1
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 *
 *
 */

// @lc code=start

/**
 * 滑动窗口，算法复杂度O(n)

   - 每次以右边界为定点，计算当前右边界的累加和
   - 寻找满足条件的最大左边界
   - 在满足条件的情况下，计算最小长度
*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int size = nums.size();
        int sum = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < size; right++)
        {
            // 1. 计算以right为右边界的连续子数组和
            sum += nums[right];

            // 2. 计算满足最小条件的左边界
            while (sum - nums[left] >= target)
            {
                sum -= nums[left];
                left++;
            }

            if (sum >= target)
            {
                // 3. 计算此时长度
                len = min(len, right - left + 1);
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end
