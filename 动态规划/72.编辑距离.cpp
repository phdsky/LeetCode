/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (62.03%)
 * Likes:    2288
 * Dislikes: 0
 * Total Accepted:    238.5K
 * Total Submissions: 384.2K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 *
 * 你可以对一个单词进行如下三种操作：
 *
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 *
 * 示例 2：
 *
 *
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   - 状态定义：

      dp[i][j]表示word1的前i个字母转换成word2的前j个字母所使用的最少操作。

   - 状态转移：

      i指向word1，j指向word2,若当前字母相同，则:

      $dp[i][j] = dp[i - 1][j - 1]$

      否则取插入、删除、替换三个操作的最小值 + 1， 即:

      $dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1$


      其中：
      - dp[i - 1][j]表示删除操作，即0～i-1的word1通过某些操作可以得到0～j的word2，那么删除word1的i位置字符串再进行同样操作即可

      - dp[i][j - 1]表示插入操作，即0～i的word1通过某些操作可以得到0～j-1的word2，那么直接在word1中直接插入word2的j位置字符即可

      - dp[i - 1][j - 1]表示替换操作，即0～i-1的word1已经可以得到0~j-1的word2，此时分为i，j字符相等和不等两种情况，不等则需要经过一次替换
*/
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[n1][n2];
    }
};
// @lc code=end
