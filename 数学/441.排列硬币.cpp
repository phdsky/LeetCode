/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (45.90%)
 * Likes:    179
 * Dislikes: 0
 * Total Accepted:    78K
 * Total Submissions: 169.9K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
 *
 * 给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 5
 * 输出：2
 * 解释：因为第三行不完整，所以返回 2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 8
 * 输出：3
 * 解释：因为第四行不完整，所以返回 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start

/**
 * 1. 暴力模拟法

   n不停减去每行个数i直到小于或等于0为止：

   如果n等于0，则恰好填满本行，行数为i；

   如果n小于0，则本行未被填满，行数为i-1。

    2. 二分法

    3. 数学法
*/
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int row = 0;
        while (n > 0)
        {
            row++;
            n -= row;
        }

        return (n < 0) ? (row - 1) : row;
    }
};
// @lc code=end
