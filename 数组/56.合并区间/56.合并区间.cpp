/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (47.36%)
 * Likes:    1236
 * Dislikes: 0
 * Total Accepted:    338.2K
 * Total Submissions: 713.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * intervals[i].length == 2
 * 0 i i 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size == 1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < size; i++) {
            int j = result.size() - 1;

            auto left = result[j];
            auto right = intervals[i];
            if (left[1] >= right[0]) {
                result[j][1] = max(result[j][1], right[1]);
            } else { // left[1] < right[0]
                result.push_back(right);
            }
        }

        return result;
    }
};
// @lc code=end

