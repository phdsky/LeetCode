/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (81.18%)
 * Likes:    2259
 * Dislikes: 0
 * Total Accepted:    742.7K
 * Total Submissions: 914.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * nums 中的所有元素 互不相同
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        backtracking(nums, 0);
        return result;
    }

private:
    void backtracking(vector<int>& nums, int start)
    {
        results.push_back(track);

        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            backtracking(nums, i + 1);
            track.pop_back();
        }
    }

    vector<int> track;
    vector<vector<int>> result;
};
// @lc code=end
