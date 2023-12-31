/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (48.17%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    42.9K
 * Total Submissions: 89.1K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
 *
 * 题目数据保证总会存在一个数值和不超过 k 的矩形区域。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出：2
 * 解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[2,2,-1]], k = 3
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 * -10^5
 *
 *
 *
 *
 * 进阶：如果行数远大于列数，该如何设计解决方案？
 *
 */

// @lc code=start
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int maxSum = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 计算以 [i, j] 为起点的最大和
                for (int x = i + 1; x <= m; x++)
                {
                    for (int y = j + 1; y <= n; y++)
                    {
                        // 统计 [x, y], [i, j] 之间的和
                        int sum = prefix[x][y] - prefix[i][y] - prefix[x][j] + prefix[i][j];
                        if (sum <= k)
                        {
                            maxSum = std::max(maxSum, sum);
                        }
                    }
                }
            }
        }

        return maxSum;
    }
};
// @lc code=end
