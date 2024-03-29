/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.41%)
 * Likes:    782
 * Dislikes: 0
 * Total Accepted:    183.2K
 * Total Submissions: 288.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
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
 * 1
 * -10
 *
 *
 *
 *
 */

// @lc code=start

/**
 * 遍历：遇到一个数就把所有子集加上该数组成新的子集，并检查哈希表中是否存在，遍历完毕即是所有子集
 */
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        subs.push_back(vector<int>());

        for (int i = 0; i < nums.size(); ++i)
        {
            subset(nums, i);
        }

        return subs;
    }

private:
    vector<vector<int>> subs;
    unordered_map<string, int> subsmap;
    // iterative
    void subset(vector<int> &nums, int id)
    {
        int size = subs.size();
        for (int i = 0; i < size; ++i)
        {
            vector<int> sub = subs[i];
            sub.push_back(nums[id]);

            string key = "";
            for (auto &s : sub)
            {
                key += s;
            }

            if (!subsmap.count(key))
            {
                subs.push_back(sub);
                subsmap[key]++;
            }
        }
    }
};
// @lc code=end
