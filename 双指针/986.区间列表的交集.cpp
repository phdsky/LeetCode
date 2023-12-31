/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 *
 * https://leetcode-cn.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (68.39%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    36.4K
 * Total Submissions: 53.3K
 * Testcase Example:  '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * 给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而
 * secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。
 *
 * 返回这 两个区间列表的交集 。
 *
 * 形式上，闭区间 [a, b]（其中 a ）表示实数 x 的集合，而 a  。
 *
 * 两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：firstList = [[0,2],[5,10],[13,23],[24,25]], secondList =
 * [[1,5],[8,12],[15,24],[25,26]]
 * 输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：firstList = [[1,3],[5,9]], secondList = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：firstList = [], secondList = [[4,8],[10,12]]
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：firstList = [[1,7]], secondList = [[3,10]]
 * 输出：[[3,7]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * firstList.length + secondList.length >= 1
 * 0 i < endi
 * endi < starti+1
 * 0 j < endj
 * endj < startj+1
 *
 *
 */

// @lc code=start

/**
 * 归并区间，每次计算两个区间的交集：

   如果存在交集，则将交集加入结果中；同时将右端较小的区间去除，因为右端较小的区间更不可能与其他区间产生交集。

   如果不存在交集，则直接去除右端较小的区间即可。
*/
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int size1 = firstList.size(), size2 = secondList.size();
        if (size1 == 0 || size2 == 0)
        {
            return {};
        }

        vector<vector<int>> section;
        int i = 0, j = 0;
        while (i < size1 && j < size2)
        {
            auto a = firstList[i], b = secondList[j];
            int low = max(a[0], b[0]);
            int high = min(a[1], b[1]);
            if (low <= high)
            {
                section.push_back({low, high});
            }

            if (a[1] < b[1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return section;
    }
};
// @lc code=end
