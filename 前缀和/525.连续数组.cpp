/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 *
 * https://leetcode.cn/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (54.68%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    73.7K
 * Total Submissions: 134.7K
 * Testcase Example:  '[0,1]'
 *
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [0,1]
 * 输出: 2
 * 说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
 *
 * 示例 2:
 *
 *
 * 输入: nums = [0,1,0]
 * 输出: 2
 * 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * nums[i] 不是 0 就是 1
 *
 *
 */

// @lc code=start

/**
 * 前缀和 + 哈希
 * 思路：可以将出现的0值换算成-1，只需用哈希记录当前前缀和是否出现，并减去当时记录的最小index即可
 *
 */
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int size = nums.size();

        int prefix = 0;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 0;

        int maxLen = 0;
        for (int i = 1; i <= size; i++)
        {
            if (nums[i - 1] == 0)
            {
                prefix -= 1;
            }
            else
            {
                prefix += 1;
            }

            if (prefix_map.count(prefix))
            {
                maxLen = max(maxLen, i - prefix_map[prefix]);
            }
            else
            {
                prefix_map[prefix] = i;
            }
        }

        return maxLen;
    }
};
// @lc code=end
