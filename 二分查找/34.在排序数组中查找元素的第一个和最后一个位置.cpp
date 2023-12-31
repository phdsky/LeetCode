/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.28%)
 * Likes:    1343
 * Dislikes: 0
 * Total Accepted:    392.2K
 * Total Submissions: 927.7K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 进阶：
 *
 *
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 *
 *
 */

// @lc code=start

/**
 * 题目要求O(logn)的二分查找算法；因此使用二分快速找到要求元素，再利用双指针寻找该元素头尾下标。
 */
class Solution
{
public:
    int binarySearch(const vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
        {
            return -1;
        }

        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            return binarySearch(nums, low, mid - 1, target);
        }
        else
        { // nums[mid] < target
            return binarySearch(nums, mid + 1, high, target);
        }

        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int size = nums.size();

        int found = binarySearch(nums, 0, size - 1, target);
        if (-1 == found)
        {
            return {-1, -1};
        }

        int left = found - 1, right = found + 1;
        while (left >= 0 && nums[left] == target)
        {
            left--;
        }
        while (right < size && nums[right] == target)
        {
            right++;
        }

        return {left + 1, right - 1};
    }
};
// @lc code=end
