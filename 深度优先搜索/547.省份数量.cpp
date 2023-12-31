/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 *
 * https://leetcode-cn.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (61.98%)
 * Likes:    752
 * Dislikes: 0
 * Total Accepted:    197.4K
 * Total Submissions: 318.5K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 *
 *
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c
 * 间接相连。
 *
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 *
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而
 * isConnected[i][j] = 0 表示二者不直接相连。
 *
 * 返回矩阵中 省份 的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] 为 1 或 0
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 *
 *
 */

// @lc code=start

/**
 * 深度优先搜索
 */
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (isConnected[i][i] == 1)
            {
                isConnected[i][i] = 0;
                num++;
                dfs(i, i, n, isConnected);
            }
        }

        return num;
    }

private:
    void dfs(int i, int j, int n, vector<vector<int>> &isConnected)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return;
        }

        for (int k = 0; k < n; k++)
        {
            if (isConnected[k][j] == 1)
            {
                isConnected[k][j] = 0;
                dfs(k, j, n, isConnected);
            }
        }

        for (int k = 0; k < n; k++)
        {
            if (isConnected[i][k] == 1)
            {
                isConnected[i][k] = 0;
                dfs(i, k, n, isConnected);
            }
        }
    }
};
// @lc code=end
