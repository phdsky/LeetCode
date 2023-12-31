/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (45.55%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    93K
 * Total Submissions: 204.2K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 *
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 *
 * 示例1:
 *
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 *
 * 示例 2:
 *
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 *
 * 示例 3:
 *
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 *
 * 示例 4:
 *
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 *
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 *
 */

// @lc code=start

/**
 * 利用双哈希，分别记录模版到字符串/字符串到模版的哈希对应；

   对于每组值，有三种情况：

   a. 模版中存在，但模版对应的值不等于当前字符，说明之前存储该模版的字符和当前对应不上，此时不满足规律；

   b. 字符串中存在，但字符串对应的值不等于当前模版，说明之前存储该字符串的模版和当前对应不上，此时不满足规律；

   c. 如果都不存在，则建立该双向哈希，直到遍历完成所有值。
*/
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream strs(s);
        vector<string> words;
        string word;
        while (strs >> word)
        {
            words.push_back(word);
        }

        if (pattern.size() != words.size())
        {
            return false;
        }

        unordered_map<char, string> charMapString;
        unordered_map<string, char> stringMapChar;
        for (int i = 0; i < words.size(); i++)
        {
            if (charMapString.count(pattern[i]) && charMapString[pattern[i]] != words[i])
            {
                return false;
            }

            if (stringMapChar.count(words[i]) && stringMapChar[words[i]] != pattern[i])
            {
                return false;
            }

            charMapString[pattern[i]] = words[i];
            stringMapChar[words[i]] = pattern[i];
        }

        return true;
    }
};
// @lc code=end
