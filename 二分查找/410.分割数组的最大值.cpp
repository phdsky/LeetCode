/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode.cn/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (59.04%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    73.2K
 * Total Submissions: 124K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组。
 *
 * 设计一个算法使得这 k 个子数组各自和的最大值最小。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [7,2,5,10,8], k = 2
 * 输出：18
 * 解释：
 * 一共有四种方法将 nums 分割为 2 个子数组。
 * 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,4,5], k = 2
 * 输出：9
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,4,4], k = 3
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= k <= min(50, nums.length)
 *
 *
 */

// @lc code=start

/**
 * 二分搜索 + 贪心
 * 思路说明：https://leetcode.cn/problems/split-array-largest-sum/solutions/21490/er-fen-cha-zhao-by-coder233-2/
 */
class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int max = INT_MIN, sum = 0;
        for (auto &n : nums)
        {
            max = std::max(max, n);
            sum += n;
        }

        int left = max, right = sum;
        // 二分区间 [max, sum)
        while (left < right)
        {
            int mid = (left + right) / 2;
            int cnt = 1, temp = 0;
            for (auto &n : nums)
            {
                temp += n;
                if (temp > mid)
                {
                    // 以当前 mid 作为子数组和的上限，计算会存在多少个子数组
                    temp = n;
                    cnt++;
                }
            }

            if (cnt > k)
            {
                // 以 mid 为子数组和上限的子数组个数多了，说明 mid 小了，下界提高
                left = mid + 1;
            }
            else
            {
                // 以 mid 为子数组和上限的子数组个数少了，说明 mid 大了，上界降低
                // mid 刚好可以使得原数组分为 k 个子数组，还需要进一步探低上界寻找是否有更小的 mid
                right = mid;
            }
        }

        // 返回下界
        return left;
    }
};
// @lc code=end
