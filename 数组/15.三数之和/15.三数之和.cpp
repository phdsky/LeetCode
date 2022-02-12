/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (34.08%)
 * Likes:    4097
 * Dislikes: 0
 * Total Accepted:    735.5K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void twoSum(int index, int target, vector<int>& nums, vector<vector<int>>& summy) {
        int len = nums.size();
        int i = index, j = len - 1;

        while (i < j) {
            int result = nums[i] + nums[j];
            if (result < target) {
                ++i;
            } else if (result > target) {
                --j;
            } else { // equals
                vector<int> sums = {-target, nums[i], nums[j]};
                summy.push_back(sums);
                ++i;
                --j;

                while (i < j && nums[i] == nums[i - 1])
                    ++i;
                while (i < j && nums[j] == nums[j + 1])
                    --j;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> summy;
        for (int i = 0; i <= len - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            twoSum(i + 1, -nums[i], nums, summy);
        }

        return summy;
    }
};
// @lc code=end

