/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.94%)
 * Likes:    2037
 * Dislikes: 0
 * Total Accepted:    373.3K
 * Total Submissions: 505.2K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
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
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        vector<string> board(n, string(n, '.'));
        backtracking(board, 0);

        return results;
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
