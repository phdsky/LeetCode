/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.61%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    108.2K
 * Total Submissions: 194.5K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
 *
 * 在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入:s = "abccccdd"
 * 输出:7
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 *
 * 示例 2:
 *
 *
 * 输入:s = "a"
 * 输入:1
 *
 *
 * 示例 3:
 *
 *
 * 输入:s = "bb"
 * 输入: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= s.length <= 2000
 * s 只能由小写和/或大写英文字母组成
 *
 *
 */

// @lc code=start

/**
 * 首先统计所有字符出现的个数；

   计算最长回文：对于偶数个数，完全满足回文约束；对于奇数个数，其偶数子部分满足回文约束，另外可以额外加1。
*/
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int size = s.size();
        if (size == 1)
        {
            return 1;
        }

        unordered_map<char, int> characters;
        for (const auto &c : s)
        {
            characters[c]++;
        }

        int count = 0;
        int c = 0;
        for (const auto &[k, v] : characters)
        {
            if (v % 2)
            {
                count += (v - 1);
                c = 1;
            }
            else
            {
                count += v;
            }
        }

        return count + c;
    }
};
// @lc code=end
