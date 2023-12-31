/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 *
 * https://leetcode.cn/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (74.34%)
 * Likes:    330
 * Dislikes: 0
 * Total Accepted:    22.8K
 * Total Submissions: 30.7K
 * Testcase Example:  '[" /","/ "]'
 *
 * 在由 1 x 1 方格组成的 n x n 网格 grid 中，每个 1 x 1 方块由 '/'、'\'
 * 或空格构成。这些字符会将方块划分为一些共边的区域。
 *
 * 给定网格 grid 表示为一个字符串数组，返回 区域的数量 。
 *
 * 请注意，反斜杠字符是转义的，因此 '\' 用 '\\' 表示。
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
 * 输入：grid = [" /","/ "]
 * 输出：2
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：grid = [" /","  "]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：grid = ["/\\","\\/"]
 * 输出：5
 * 解释：回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 30
 * grid[i][j] 是 '/'、'\'、或 ' '
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
 * 难点在于如何将斜杠区域转化为并查集来套用；
 * 可以将每个方块划分为四份，可以看官方题解的拆解图和子块编码方式
 * 在方块内部，'/'与'\'和' '分别可代表一种联通方式；在方块外部，也会存在两种联通方式
 */
class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int size = 4 * n * n;
        auto uf = std::make_unique<UF>(size);

        for (int i = 0; i < n; i++)
        {
            auto row = grid[i].c_str();
            for (int j = 0; j < n; j++)
            {
                auto c = row[j];
                int index = 4 * (i * n + j);

                // union inner cube regions
                if (c == '/')
                {
                    uf->Union(index, index + 3);
                    uf->Union(index + 1, index + 2);
                }
                else if (c == '\\')
                {
                    uf->Union(index, index + 1);
                    uf->Union(index + 2, index + 3);
                }
                else
                {
                    uf->Union(index, index + 1);
                    uf->Union(index + 1, index + 2);
                    uf->Union(index + 2, index + 3);
                }

                // union cross cube regions
                if (j + 1 < n)
                {
                    uf->Union(index + 1, 4 * (i * n + j + 1) + 3);
                }
                if (i + 1 < n)
                {
                    uf->Union(index + 2, 4 * ((i + 1) * n + j));
                }
            }
        }

        return uf->Count();
    }
};
// @lc code=end
