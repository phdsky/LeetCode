/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (54.67%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    186.1K
 * Total Submissions: 340.5K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */

// @lc code=start
class Solution 
{
public:
    string reverseVowels(string s) 
    {
        int size = s.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int i = 0, j = size - 1;
        while (i < j)
        {
            
            if (vowels.find(s[i]) != vowels.end())
            {
                // 1. i 为元音， j 为元音
                if (vowels.find(s[j]) != vowels.end())
                {
                    std::swap(s[i], s[j]);
                    ++i;
                    --j;
                }
                else // 2. i 为元音， j 不为元音
                {
                    --j;
                }
            }
            else
            {
                // 3. i 不为元音， j 为元音
                if (vowels.find(s[j]) != vowels.end())
                {
                    ++i;
                }
                else // 4. i 不为元音， j 不为元音
                {
                    ++i;
                    --j;
                }
            }
        }

        return s;
    }
};
// @lc code=end

