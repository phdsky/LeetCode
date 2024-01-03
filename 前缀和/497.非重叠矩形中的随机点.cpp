/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 *
 * https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (41.97%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 59.3K
 * Testcase Example:  '["Solution","pick","pick","pick","pick","pick"]\n' +
  '[[[[-2,-2,1,1],[2,2,4,6]]],[],[],[],[],[]]'
 *
 * 给定一个由非重叠的轴对齐矩形的数组 rects ，其中 rects[i] = [ai, bi, xi, yi] 表示 (ai, bi) 是第 i
 * 个矩形的左下角点，(xi, yi) 是第 i
 * 个矩形的右上角点。设计一个算法来随机挑选一个被某一矩形覆盖的整数点。矩形周长上的点也算做是被矩形覆盖。所有满足要求的点必须等概率被返回。
 *
 * 在给定的矩形覆盖的空间内的任何整数点都有可能被返回。
 *
 * 请注意 ，整数点是具有整数坐标的点。
 *
 * 实现 Solution 类:
 *
 *
 * Solution(int[][] rects) 用给定的矩形数组 rects 初始化对象。
 * int[] pick() 返回一个随机的整数点 [u, v] 在给定的矩形所覆盖的空间内。
 *
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入:
 * ["Solution", "pick", "pick", "pick", "pick", "pick"]
 * [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
 * 输出:
 * [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]
 *
 * 解释：
 * Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
 * solution.pick(); // 返回 [1, -2]
 * solution.pick(); // 返回 [1, -1]
 * solution.pick(); // 返回 [-1, -2]
 * solution.pick(); // 返回 [-2, -2]
 * solution.pick(); // 返回 [0, 0]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rects.length <= 100
 * rects[i].length == 4
 * -10^9 <= ai < xi <= 10^9
 * -10^9 <= bi < yi <= 10^9
 * xi - ai <= 2000
 * yi - bi <= 2000
 * 所有的矩形不重叠。
 * pick 最多被调用 10^4 次。
 *
 *
 */

// @lc code=start

/**
 * 前缀和 + 二分查找
 * 题解思路： https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/solutions/1543083/by-nehzil-9qwd/
 */
class Solution
{
public:
    Solution(vector<vector<int>> &rects) :
        rects(rects)
    {
        arr.push_back(0);
        for (auto &rec : rects)
        {
            arr.push_back(arr.back() + (rec[3] - rec[1] + 1) * (rec[2] - rec[0] + 1));
        }
    }

    vector<int> pick()
    {
        int k = rand() % arr.back() + 1;
        int left = 0, right = rects.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        vector<int> target = rects[right - 1];
        int x = target[2] - target[0] + 1;
        int y = target[3] - target[1] + 1;

        return {rand() % x + target[0], rand() % y + target[1]};
    }

private:
    vector<vector<int>> rects;
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end
