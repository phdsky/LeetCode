/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.17%)
 * Likes:    4721
 * Dislikes: 0
 * Total Accepted:    880.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) 
                return false;
            ++i;
            --j;
        }

        return true;
    }
    
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0) return "";

        for (int len = length; len > 1; --len) {
            for (int id = 0; id <= length - len; ++id) {
                if (s[id] == s[id + len - 1] && 
                    isPalindrome(s, id + 1, id + len - 2))
                    return s.substr(id, len);
            }
        }

        return s.substr(0, 1);
    }
};
// @lc code=end

