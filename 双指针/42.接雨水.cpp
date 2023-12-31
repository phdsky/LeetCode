/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (63.18%)
 * Likes:    4923
 * Dislikes: 0
 * Total Accepted:    826.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int size = height.size();

        // 以竖条为参考坐标，a[i] 的接雨水数为 min[max[a[0...left]], max[a[right...size)]] - a[i]
        // 所以先分别计算 a[i] 的左右最高柱子
        vector<int> left(size, 0);
        int leftMax = 0;
        for (int i = 0; i < size; i++)
        {
            leftMax = max(leftMax, height[i]);
            left[i] = leftMax;
        }
        
        vector<int> right(size, 0);
        int rightMax = 0;
        for (int j = size - 1; j >= 0; j--)
        {
            rightMax = max(rightMax, height[j]);
            right[j] = rightMax;
        }

        int rainDrops = 0;
        for (int k = 1; k < size - 1; k++)
        {
            rainDrops += min(left[k], right[k]) - height[k];
        }

        return rainDrops;
    }
};
// @lc code=end

