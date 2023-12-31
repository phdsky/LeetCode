/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (64.34%)
 * Likes:    998
 * Dislikes: 0
 * Total Accepted:    289.7K
 * Total Submissions: 449.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start

/**
 * 回溯 + 哈希
 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        dfs(0, nums, nums.size());

        return permutations;
    }

private:
    void dfs(int pos, vector<int> &nums, int len)
    {
        if (pos == len)
        {
            string str = "";
            for (auto &n : nums)
            {
                str += n;
            }
            if (!permuteMap.count(str))
            {
                permuteMap[str]++;
                permutations.push_back(nums);
                return;
            }
        }

        for (int i = pos; i < nums.size(); ++i)
        {
            swap(nums[i], nums[pos]);
            dfs(pos + 1, nums, len);
            swap(nums[i], nums[pos]);
        }
    }

    vector<vector<int>> permutations;
    unordered_map<string, int> permuteMap;
};
// @lc code=end
