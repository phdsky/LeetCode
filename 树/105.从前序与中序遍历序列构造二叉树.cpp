/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.52%)
 * Likes:    1289
 * Dislikes: 0
 * Total Accepted:    262.6K
 * Total Submissions: 372.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * inorder.length == preorder.length
 * -3000
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
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

/**
 * 从二叉树的前序遍历和中序遍历中寻找元素分布的规律，递归构造对应的下标元素即可。
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        int val = preorder[preStart];
        auto iter = find(inorder.begin(), inorder.end(), val);
        int index = iter - inorder.begin();

        TreeNode *node = new TreeNode(val);
        node->left = build(preorder, preStart + 1, preStart + index - inStart,
                           inorder, inStart, index - 1);
        node->right = build(preorder, preStart + index - inStart + 1, preEnd,
                            inorder, index + 1, inEnd);

        return node;
    }
};
// @lc code=end
