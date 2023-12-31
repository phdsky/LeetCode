/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 *
 * https://leetcode-cn.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (60.99%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 157.1K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * 给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，数组的所有排列应该是 等可能 的。
 *
 * 实现 Solution class:
 *
 *
 * Solution(int[] nums) 使用整数数组 nums 初始化对象
 * int[] reset() 重设数组到它的初始状态并返回
 * int[] shuffle() 返回数组随机打乱后的结果
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入
 * ["Solution", "shuffle", "reset", "shuffle"]
 * [[[1, 2, 3]], [], [], []]
 * 输出
 * [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
 *
 * 解释
 * Solution solution = new Solution([1, 2, 3]);
 * solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回
 * [3, 1, 2]
 * solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
 * solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^6 <= nums[i] <= 10^6
 * nums 中的所有元素都是 唯一的
 * 最多可以调用 5 * 10^4 次 reset 和 shuffle
 *
 *
 */

// @lc code=start

/**
 * 经典的洗牌算法

   思路是在前$n - 1$张牌洗好的情况下，第$n$张牌随机与前$n - 1$张牌的其中一张牌交换或者不换，即是随机洗牌。
*/
class Solution
{
public:
    Solution(vector<int> nums)
    {
        elements = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return elements;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> vShuffle = elements;
        for (int i = 1; i < vShuffle.size(); ++i)
        {
            int r = rand() % (i + 1);
            if (r != i)
            {
                swap(vShuffle[r], vShuffle[i]);
            }
        }

        return vShuffle;
    }

private:
    vector<int> elements;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
