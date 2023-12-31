/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.00%)
 * Likes:    1725
 * Dislikes: 0
 * Total Accepted:    408.9K
 * Total Submissions: 951K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 *
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 *
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1], target = 0
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^4
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4
 *
 *
 *
 *
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 *
 */

// @lc code=start

/**
 * 题目要求O(logn)的二分查找算法；因此根据旋转排序数组特性，查找旋转点的位置，分析前后部分是否有序分进行二分查找。
 */
class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, int begin, int end)
    {
        if (begin > end)
        {
            return -1;
        }
        else if (begin == end)
        {
            if (nums[begin] == target)
            {
                return end;
            }
            else
            {
                return -1;
            }
        }

        int mid = (begin + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            return binarySearch(nums, target, begin, mid - 1);
        }
        else
        { // nums[mid] < target
            return binarySearch(nums, target, mid + 1, end);
        }

        return -1;
    }

    int searchTarget(vector<int> &nums, int target, int begin, int end)
    {
        if (begin > end)
        {
            return -1;
        }
        else if (begin == end)
        {
            if (nums[begin] == target)
            {
                return end;
            }
            else
            {
                return -1;
            }
        }

        int mid = (begin + end) / 2;
        int id0 = -2, id1 = -2;
        if (nums[begin] < nums[mid])
        { // former part is sorted
            id0 = binarySearch(nums, target, begin, mid);
            id1 = searchTarget(nums, target, mid + 1, end);
        }
        else
        { // last part is sorted
            id0 = searchTarget(nums, target, begin, mid);
            id1 = binarySearch(nums, target, mid + 1, end);
        }

        if (id0 != -1 || id1 != -1)
        {
            return (id0 != -1) ? id0 : id1;
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        return searchTarget(nums, target, 0, nums.size() - 1);
    }
};
// @lc code=end
