/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
 *
 * https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/
 *
 * algorithms
 * Medium (42.12%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 38.6K
 * Testcase Example:  '[6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]'
 *
 * 给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。
 *
 * 请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：
 *
 *
 * mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
 * maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替。
 *
 *
 * 返回数组 answer 。
 *
 *
 *
 * 示例 1 ：
 *
 *
 *
 *
 * 输入：root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries =
 * [2,5,16]
 * 输出：[[2,2],[4,6],[15,-1]]
 * 解释：按下面的描述找出并返回查询的答案：
 * - 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
 * - 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
 * - 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
 *
 *
 * 示例 2 ：
 *
 *
 *
 *
 * 输入：root = [4,null,9], queries = [3]
 * 输出：[[-1,4]]
 * 解释：树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [2, 10^5] 内
 * 1 <= Node.val <= 10^6
 * n == queries.length
 * 1 <= n <= 10^5
 * 1 <= queries[i] <= 10^6
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
    {
        vector<vector<int>> closests;
        midTraverse(root);

        for (auto& q : queries)
        {
            int left = 0, right = values.size() - 1;
            int min = values[left], max = values[right];
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (q == values[mid])
                {
                    min = q;
                    max = q;
                    break;
                }
                else if (q > values[mid])
                {
                    min = values[mid];
                    left = mid + 1;
                }
                else
                {
                    max = values[mid];
                    right = mid - 1;
                }
            }

            if (q < values[0])
                min = -1;
            if (q > values[values.size() - 1])
                max = -1;
            closests.push_back({min, max});
        }

        return closests;
    }

private:
    void midTraverse(TreeNode* node)
    {
        if (node == nullptr)
            return;

        midTraverse(node->left);
        values.emplace_back(node->val);
        midTraverse(node->right);
    }

    vector<int> values;
};
// @lc code=end
