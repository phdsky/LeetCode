/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 *
 * https://leetcode-cn.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (50.66%)
 * Likes:    595
 * Dislikes: 0
 * Total Accepted:    116.5K
 * Total Submissions: 229.9K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 *
 * 注意:
 *
 *
 * 可以认为区间的终点总是大于它的起点。
 * 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 *
 *
 * 示例 1:
 *
 *
 * 输入: [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * 输出: 1
 *
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 *
 * 示例 2:
 *
 *
 * 输入: [ [1,2], [1,2], [1,2] ]
 *
 * 输出: 2
 *
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 *
 * 示例 3:
 *
 *
 * 输入: [ [1,2], [2,3] ]
 *
 * 输出: 0
 *
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 *
 */

// @lc code=start

/**
 * 按区间结束顺序排序，如果都是在一个节点结束的，则选择开始最晚的节点；此贪心策略可以安排最多的区间。

   [时间管理大师理解](https://leetcode-cn.com/problems/non-overlapping-intervals/solution/gua-he-xin-shou-peng-you-de-shi-pin-ti-j-ic00/)
*/
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int size = intervals.size();
        if (size <= 1)
        {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        int count = 0;
        int right = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (intervals[i][0] >= right)
            {
                right = intervals[i][1];
                count++;
            }
        }

        return size - count;
    }
};
// @lc code=end
