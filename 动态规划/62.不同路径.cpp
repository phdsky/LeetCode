/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (66.90%)
 * Likes:    1348
 * Dislikes: 0
 * Total Accepted:    408.7K
 * Total Submissions: 610.9K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 *
 *
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 *
 *
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 *
 *
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 题目数据保证答案小于等于 2 * 10^9
 *
 *
 */

// @lc code=start

/**
 * 动态规划

   第(i, j)位置可以由(i - 1, j) 和 (i, j - 1)两个位置递推过来，由此可得递推方程。

   由于每次只能向下或者向右移动一步，因此初始化条件到达(i, 0) 和 (0, j)路径数都为1。
*/
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> path(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            path[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            path[0][j] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }

        return path[m - 1][n - 1];
    }
};
// @lc code=end
