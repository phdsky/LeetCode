/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (44.25%)
 * Likes:    1528
 * Dislikes: 0
 * Total Accepted:    302.1K
 * Total Submissions: 682.5K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 *
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 *
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 *
 * 假设你总是可以到达数组的最后一个位置。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * 0
 *
 *
 */

// @lc code=start

/**
 * 贪心

   从后往前遍历数组，每次找到可以到达最后一个位置的最前下标；直到下标为0为止，经过的步数即为跳跃次数。
*/
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        else if (n == 2)
        {
            return 1;
        }

        int step = 0;
        n--;
        while (n)
        {
            for (int i = 0; i < n; i++)
            {
                if (i + nums[i] >= n)
                {
                    n = i;
                    break;
                }
            }
            step++;
        }

        return step;
    }
};
// @lc code=end
