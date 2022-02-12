/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (43.24%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    35.1K
 * Total Submissions: 80.9K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * 给定一个正整数数组 nums和整数 k 。
 * 
 * 请找出该数组内乘积小于 k 的连续的子数组的个数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [10,5,2,6], k = 100
 * 输出: 8
 * 解释: 8个乘积小于100的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,2,3], k = 0
 * 输出: 0
 * 
 * 
 * 
 * 提示: 
 * 
 * 
 * 1 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || k == 1) {
            return 0;
        }

        int size = nums.size();
        int num = 0;
        int product = 1;
        for (int left = 0, right = 0; right < size; right++) {
            // 1. 计算当前右边界的乘积
            product *= nums[right];
           
            // 2. 寻找满足条件的左边界 
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // 3. 计算区间[left, right]间满足条件的个数
            num += right - left + 1;
        }

        return num;
    }
};
// @lc code=end

