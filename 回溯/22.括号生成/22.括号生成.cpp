/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.36%)
 * Likes:    2515
 * Dislikes: 0
 * Total Accepted:    468.7K
 * Total Submissions: 605.7K
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
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> parenthesis;
    backtrace("", parenthesis, n, n);

    return parenthesis;
  }

  void backtrace(string parent, vector<string> &parenthesis, int left, int right) {
    if (left == 0 && right == 0) {
      parenthesis.push_back(parent);
      return;
    }

    if (left > right)
      return;

    if (left > 0)
      backtrace(parent + '(', parenthesis, left - 1, right);

    if (right > 0)
      backtrace(parent + ')', parenthesis, left, right - 1);
  }
};
// @lc code=end

