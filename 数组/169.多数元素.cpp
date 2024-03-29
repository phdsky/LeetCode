/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (66.52%)
 * Likes:    1240
 * Dislikes: 0
 * Total Accepted:    424.1K
 * Total Submissions: 637.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：[3,2,3]
 * 输出：3
 *
 * 示例 2：
 *
 *
 * 输入：[2,2,1,1,1,2,2]
 * 输出：2
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 *
 *
 */

// @lc code=start

/**
 * 遍历利用哈希表存储元素出现次数，超出一半即为多数元素
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int half = nums.size() / 2;
        unordered_map<int, int> majority;
        for (const auto &num : nums)
        {
            majority[num] += 1;

            if (majority[num] > half)
            {
                return num;
            }
        }

        return nums[0];
    }
};
// @lc code=end
