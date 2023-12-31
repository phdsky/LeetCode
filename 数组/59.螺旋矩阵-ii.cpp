/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (77.94%)
 * Likes:    578
 * Dislikes: 0
 * Total Accepted:    152.4K
 * Total Submissions: 195.6K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start

/**
 * 按螺旋矩阵生成方式模拟生成
 */
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int row = n, col = n;
        int sum = n * n;
        int num = sum;

        int up = 0, down = row - 1, left = 0, right = col - 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while (num > 0)
        {
            for (int i = left; num > 0 && i <= right; i++)
            {
                num--;
                matrix[up][i] = sum - num;
            }
            up++;

            for (int i = up; num > 0 && i <= down; i++)
            {
                num--;
                matrix[i][right] = sum - num;
            }
            right--;

            for (int i = right; num > 0 && i >= left; i--)
            {
                num--;
                matrix[down][i] = sum - num;
            }
            down--;

            for (int i = down; num > 0 && i >= up; i--)
            {
                num--;
                matrix[i][left] = sum - num;
            }
            left++;
        }

        return matrix;
    }
};
// @lc code=end
