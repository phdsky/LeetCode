/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (36.22%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    58.1K
 * Total Submissions: 159.8K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：points = [[1,1],[2,2],[3,3]]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * points[i].length == 2
 * -10^4 i, yi 
 * points 中的所有点 互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }

        int num = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int x1 = points[i][0] - points[j][0];
                int y1 = points[i][1] - points[j][1];
                
                int count = 2;
                for (int k = j + 1; k < n; k++) {
                    int x2 = points[i][0] - points[k][0];
                    int y2 = points[i][1] - points[k][1];
                    
                    if (x1 * y2 == x2 * y1) {
                        count++;
                    }
                }

                num = max(num, count);
            }
        }

        return num;
    }
};
// @lc code=end

