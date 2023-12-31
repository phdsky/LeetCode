/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode.cn/problems/next-permutation/description/
 *
 * algorithms
 * Medium (38.69%)
 * Likes:    2387
 * Dislikes: 0
 * Total Accepted:    474.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
 * 
 * 
 * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
 * 
 * 
 * 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列
 * 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。
 * 
 * 
 * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
 * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
 * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
 * 
 * 
 * 给你一个整数数组 nums ，找出 nums 的下一个排列。
 * 
 * 必须 原地 修改，只允许使用额外常数空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 1) 
        {
            return;
        }

        // 1. 从后向前查找第一个相邻升序对 [i, j], 此时 [j, size) 已是逆序
        int j = size - 1;
        int i = -1;
        for (; j >= 1; j--) 
        {
            if (nums[j - 1] < nums[j]) 
            {
                i = j - 1;
                break;
            }
        }
        // std::cout << '[' << i << ", " << j << ']' << std::endl;
        if (i == -1) // 没有任何升序对，不存在一个字典序更大的排列
        {
            std::sort(nums.begin(), nums.end());
            return;
        }

        // 2. 在 [j, size) 中从后向前寻找第一个大于 a[i] 的数 a[k]，交换 a[k] 和 a[i]
        for (int k = size - 1; k >= j; k--)
        {
            if (nums[k] > nums[i])
            {
                std::swap(nums[k], nums[i]);
                break;
            }
        }

        // 3. 此时 [j, size) 仍保持逆序，倒置即可得到下一个排列
        i = size - 1;
        while (i > j)
        {
            std::swap(nums[i], nums[j]);
            --i;
            ++j;
        }
    }
};
// @lc code=end

