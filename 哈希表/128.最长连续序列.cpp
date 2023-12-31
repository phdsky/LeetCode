/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (55.05%)
 * Likes:    1597
 * Dislikes: 0
 * Total Accepted:    370.9K
 * Total Submissions: 673.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 *
 *
 */

// @lc code=start

/**
 * 哈希表

   首先使用 set 将原数组去重并放入 hash，针对每个元素 n，只要利用 hash 查找 n+1 是否在哈希表中即可
   由于被枚举过的后续元素已不再可能是最长连续序列中的元素之一（最长序列的元素是连续的），因此可以跳过以避免 TLE
*/
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0) return 0;

        set<int> numSet;
        for (int i = 0; i < size; i++)
        {
            numSet.insert(nums[i]);
        }

        set<int> calculated;
        int longest = 1;
        for (const auto &num : numSet)
        {
            if (calculated.count(num))
            {
                continue;
            }

            int len = 1;
            int n = num;
            while (numSet.count(n + 1))
            {
                n += 1;
                len += 1;
                calculated.insert(n);
            }
            if (len > longest)
            {
                longest = len;
            }
        }

        return longest;
    }
};
// @lc code=end
