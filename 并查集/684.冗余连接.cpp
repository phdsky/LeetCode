/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (67.36%)
 * Likes:    576
 * Dislikes: 0
 * Total Accepted:    99.3K
 * Total Submissions: 147.5K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的那个。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 *
 *
 */

// @lc code=start
class UF
{
public:
    /**
     * @brief   Initializes an empty union-find data structure with n
     *          Initially, each element is in its own set.
     * @param   n the number of elements
     * @throws  std::invalid_argument if n < 0
     */
    UF(int n)
    {
        if (n < 0)
        {
            throw std::invalid_argument("n < 0");
        }

        count = n;
        length = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~UF()
    {
        delete[] parent;
        delete[] rank;
    }

    /**
     * @brief   Returns the canonical element of the set containing element p
     * @param   p an element
     * @throws  std::invalid_argument unless 0 <= p < n
     */
    int Find(int p)
    {
        Validate(p);
        while (p != parent[p])
        {
            parent[p] = parent[parent[p]]; // path compression by halving
            p = parent[p];
        }
        return p;
    }

    /**
     * @brief   Returns the number of sets
     */
    int Count()
    {
        return count;
    }

    /**
     * @brief       Returns true if the two elements are in the same set
     * @param       p one element, q the other element
     * @return      true if p and q are in the same set; false otherwise
     * @throws      std::invalid_argument unless both 0 <= p < n and 0 <= q < n
     * @deprecated  Replace with two calls to find(int)
     */
    bool Connected(int p, int q)
    {
        return Find(p) == Find(q);
    }

    /**
     * @brief   Merges the set containing element p with the set containing element q
     * @param   p one element, q the other element
     * @throws  std::invalid_argument unless both 0 <= p < n and 0 <= q < n
     */
    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ)
        {
            return;
        }

        if (rank[rootP] < rank[rootQ])
        {
            parent[rootP] = rootQ;
        }
        else if (rank[rootP] > rank[rootQ])
        {
            parent[rootQ] = rootP;
        }
        else
        {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }

private:
    // validate that p is a valid index
    void Validate(int p)
    {
        int n = length;
        if (p < 0 || p >= n)
        {
            throw std::invalid_argument("index p is not between 0 and (n - 1)");
        }
    }

    int *parent; // parent[i] = parent of i
    int *rank;   // rank[i] = rank of subtree rooted at i (never more than 31)
    int count;   // number of components
    int length;  // array length
};               // class UF

/**
 * 利用并查集的性质：如果两个节点已经连接了，那么该连接则是冗余的，存下返回最后一帧即可
 */
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        auto uf = std::make_unique<UF>(n);

        vector<vector<int>> results;
        for (int i = 0; i < n; i++)
        {
            vector<int> edge = edges[i];
            int p = edge[0] - 1;
            int q = edge[1] - 1;

            if (uf->Connected(p, q))
            {
                results.push_back(edge);
            }
            else
            {
                uf->Union(p, q);
            }
        }

        return results[results.size() - 1];
    }
};
// @lc code=end
