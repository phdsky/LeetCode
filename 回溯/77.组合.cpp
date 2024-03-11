/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.07%)
 * Likes:    1596
 * Dislikes: 0
 * Total Accepted:    667.4K
 * Total Submissions: 867K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        N = n;
        vector<int> track;
        backtracking(track, 1, k);
        return result;
    }

private:
    void backtracking(vector<int>& track, int start, int k)
    {
        if (k == 0)
        {
            result.push_back(track);
            return;
        }

        for (int i = start; i <= N; i++)
        {
            track.push_back(i);
            backtracking(track, i + 1, k - 1);
            track.pop_back();
        }
    }

    int N;
    vector<int> track;
    vector<vector<int>> result;
};
// @lc code=end
