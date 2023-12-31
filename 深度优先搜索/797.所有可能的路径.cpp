/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 *
 * https://leetcode-cn.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (78.87%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 77.2K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
 *
 * graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：graph = [[1,2],[3],[3],[]]
 * 输出：[[0,1,3],[0,2,3]]
 * 解释：有两条路径 0 -> 1 -> 3 和 0 -> 2 -> 3
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * 输出：[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == graph.length
 * 2 <= n <= 15
 * 0 <= graph[i][j] < n
 * graph[i][j] != i（即不存在自环）
 * graph[i] 中的所有元素 互不相同
 * 保证输入为 有向无环图（DAG）
 *
 *
 *
 *
 */

// @lc code=start

/**
 * 深度优先搜索

   使用深度优先搜索的方式求出所有可能的路径。从0号点出发，使用栈记录路径上的点。每次我们遍历到点n−1，就将栈中记录的路径加入到答案中。

   特别地，因为本题中的图为有向无环图（DAG），搜索过程中不会反复遍历同一个点，因此我们无需判断当前点是否遍历过。
*/
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        path.push_back(0);
        dfs(graph, 0, n - 1);

        return paths;
    }

private:
    vector<vector<int>> paths;
    vector<int> path;

    void dfs(vector<vector<int>> &graph, int x, int n)
    {
        if (x == n)
        {
            paths.push_back(path);
            return;
        }

        for (auto &g : graph[x])
        {
            path.push_back(g);
            dfs(graph, g, n);
            path.pop_back();
        }
    }
};
// @lc code=end
