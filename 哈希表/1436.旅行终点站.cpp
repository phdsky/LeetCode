/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 *
 * https://leetcode-cn.com/problems/destination-city/description/
 *
 * algorithms
 * Easy (82.16%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 53.6K
 * Testcase Example:  '[["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]'
 *
 * 给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从
 * cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。
 *
 * 题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * 输出："Sao Paulo"
 * 解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" ->
 * "Lima" -> "Sao Paulo" 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：paths = [["B","C"],["D","B"],["C","A"]]
 * 输出："A"
 * 解释：所有可能的线路是：
 * "D" -> "B" -> "C" -> "A". 
 * "B" -> "C" -> "A". 
 * "C" -> "A". 
 * "A". 
 * 显然，旅行终点站是 "A" 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：paths = [["A","Z"]]
 * 输出："Z"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * 所有字符串均由大小写英文字母和空格字符组成。
 *
 *
 */

// @lc code=start

/**
 * 基本思路：

题目数据保证线路图会形成一条不存在循环的线路，且恰有一个旅行终点/起点站。路线图中的路径是可以相互连接的，故所有起点-终点相互抵消只会剩下整条路径的起点和终点。

因此可以使用哈希表，遍历路线图，每小段路径的城市作为起点-1，终点则+1；最终所有城市除了最终的起点和终点都是0，终点站即为1，遍历哈希表即可。

时间复杂度O(n)，空间复杂度O(n)
*/
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> citys;
        for (const auto &path : paths)
        {
            if (citys.count(path[0]))
            {
                citys[path[0]] -= 1;
            }
            else
            {
                citys[path[0]] = -1;
            }

            if (citys.count(path[1]))
            {
                citys[path[1]] += 1;
            }
            else
            {
                citys[path[1]] = 1;
            }
        }

        for (const auto &city : citys)
        {
            if (city.second == 1)
            {
                return city.first;
            }
        }

        return "";
    }
};
// @lc code=end
