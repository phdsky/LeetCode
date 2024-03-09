/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.29%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    141.7K
 * Total Submissions: 172.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        N = n;
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);

        return results.size();
    }

    void backtracking(vector<string>& board, int row)
    {
        if (row == N)
        {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++)
        {
            if (!isValid(board, row, col))
                continue;

            board[row][col] = 'Q';
            backtracking(board, row + 1);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string>& board, int row, int col)
    {
        // up
        for (int r = 0; r < row; r++)
        {
            if (board[r][col] == 'Q')
                return false;
        }

        // up left
        int r = row - 1;
        int c = col - 1;
        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // up right
        r = row - 1;
        c = col + 1;
        while (r >= 0 && c < N)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }

private:
    int N;
    vector<vector<string>> results;
};
// @lc code=end
