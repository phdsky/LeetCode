/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (66.88%)
 * Likes:    996
 * Dislikes: 0
 * Total Accepted:    273.9K
 * Total Submissions: 409.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 *
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 *
 *
 */

// @lc code=start

/**
 * 将单词编码为统计字符个数的字符串作为哈希表的key，相同key的即为一组。
 */
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int size = strs.size();
        if (size < 2)
        {
            return {strs};
        }

        vector<vector<string>> group;
        unordered_map<string, vector<string>> hash;
        for (const auto &str : strs)
        {
            string counter(26, '0');
            for (const auto &s : str)
            {
                counter[s - 'a']++;
            }

            hash[counter].emplace_back(str);
        }

        for (const auto &h : hash)
        {
            group.emplace_back(h.second);
        }

        return group;
    }
};
// @lc code=end
