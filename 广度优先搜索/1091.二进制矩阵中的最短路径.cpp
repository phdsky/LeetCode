/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 *
 * https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (38.41%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    39.8K
 * Total Submissions: 103.6K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。
 *
 * 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n -
 * 1)）的路径，该路径同时满足下述要求：
 *
 *
 * 路径途经的所有单元格都的值都是 0 。
 * 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
 *
 *
 * 畅通路径的长度 是该路径途经的单元格总数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [[0,1],[1,0]]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
 * 输出：4
 *
 *
 * 示例 3：
 *
 *
 * 输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start

/**
 * 1. 广度优先搜索

   求最短路径，每一步需要对单元格中所有可行的方向扩展；如果扩展中遇到访问过的节点，则该路径一定没有上一条路径短；

   使用广度优先搜索，每一步代表了当前可行路径的最远距离，可以保证寻找到的路径是最短的。

2. 深度优先搜索

   使用深度优先搜索需要遍历所有可行的路径，再比较所有路径最短者；此题会超时。
*/
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});

        const int direction[8][2] = {
            {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
        int path = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [i, j] = q.front();
                q.pop();
                if (i == n - 1 && j == n - 1)
                {
                    return path;
                }

                for (int k = 0; k < 8; k++)
                {
                    int ni = i + direction[k][0];
                    int nj = j + direction[k][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                    {
                        continue;
                    }

                    if (grid[ni][nj] == 0)
                    {
                        q.push({ni, nj});
                        grid[ni][nj] = 1;
                    }
                }
            }

            path++;
        }

        return -1;
    }
};
// @lc code=end
