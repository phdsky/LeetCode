/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (67.56%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    168.1K
 * Total Submissions: 248.8K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 *
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 *
 *
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 *
 *
 * 示例 2:
 *
 *
 * 输入: rowIndex = 0
 * 输出: [1]
 *
 *
 * 示例 3:
 *
 *
 * 输入: rowIndex = 1
 * 输出: [1,1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 0
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 *
 */

// @lc code=start

/**
 * 逐行生成杨辉三角，构造两个数组交替计算
 */
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> pre, cur;
        for (int i = 0; i <= rowIndex; i++)
        {
            cur.resize(i + 1);
            cur[0] = 1;
            cur[i] = 1;
            for (int j = 1; j < i; j++)
            {
                cur[j] = pre[j] + pre[j - 1];
            }

            pre = cur;
        }

        return cur;
    }
};
// @lc code=end
