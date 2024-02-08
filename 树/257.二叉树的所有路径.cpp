/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.71%)
 * Likes:    1095
 * Dislikes: 0
 * Total Accepted:    367.9K
 * Total Submissions: 520.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        string path = "";
        dfs(root, path, paths);

        return paths;
    }

private:
    void dfs(TreeNode* node, string& path, vector<string>& paths)
    {
        path += to_string(node->val);

        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(path);
            return;
        }

        if (node->left != nullptr)
        {
            path += "->";
            dfs(node->left, path, paths);
            int del = to_string(node->left->val).size() + 2;
            path = path.substr(0, path.size() - del);
        }

        if (node->right != nullptr)
        {
            path += "->";
            dfs(node->right, path, paths);
            int del = to_string(node->right->val).size() + 2;
            path = path.substr(0, path.size() - del);
        }
    }
};
// @lc code=end
