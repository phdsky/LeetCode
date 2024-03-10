/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.56%)
 * Likes:    3529
 * Dislikes: 0
 * Total Accepted:    803.2K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：["()"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string str = "";
        backtracking(str, n, n);
        return result;
    }

private:
    void backtracking(string& str, int left, int right)
    {
        if (left < 0 || right < 0 || left > right)
            return;

        if (left == 0 && right == 0)
        {
            result.push_back(str);
        }

        // left trace
        str += '(';
        backtracking(str, left - 1, right);
        str.pop_back();

        str += ')';
        backtracking(str, left, right - 1);
        str.pop_back();
    }

    vector<string> result;
};
// @lc code=end
