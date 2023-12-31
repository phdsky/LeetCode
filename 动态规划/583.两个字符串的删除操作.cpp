/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 *
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (63.88%)
 * Likes:    399
 * Dislikes: 0
 * Total Accepted:    70.6K
 * Total Submissions: 110.3K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
 *
 * 每步 可以删除任意一个字符串中的一个字符。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 *
 *
 * 示例  2:
 *
 *
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * 1 <= word1.length, word2.length <= 500
 * word1 和 word2 只包含小写英文字母
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   两个字符分别减去最长公共子序列剩余的字符，从原字符去除即可使两个字符串相等

   因此两个字符串相互演变所需的步数为：两个字符串长度之和 - 2 * 两个字符串最长公共子序列

   最长公共子序列求解见题 [1143.最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence)
*/
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int size1 = word1.size(), size2 = word2.size();
        vector<vector<int>> lcs(size1 + 1, vector<int>(size2 + 1, 0));

        for (int i = 1; i <= size1; i++)
        {
            char s1 = word1[i - 1];
            for (int j = 1; j <= size2; j++)
            {
                char s2 = word2[j - 1];

                if (s1 == s2)
                {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else
                {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        return size1 + size2 - 2 * lcs[size1][size2];
    }
};
// @lc code=end
