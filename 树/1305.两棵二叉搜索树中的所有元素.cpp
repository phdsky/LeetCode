/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 *
 * https://leetcode.cn/problems/all-elements-in-two-binary-search-trees/description/
 *
 * algorithms
 * Medium (78.11%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    52.4K
 * Total Submissions: 67.1K
 * Testcase Example:  '[2,1,4]\n[1,0,3]'
 *
 * 给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root1 = [2,1,4], root2 = [1,0,3]
 * 输出：[0,1,1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root1 = [1,null,8], root2 = [8,1]
 * 输出：[1,1,8,8]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每棵树的节点数在 [0, 5000] 范围内
 * -10^5 <= Node.val <= 10^5
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ele;
        midTraverse(root1, ele);
        midTraverse(root2, ele);
        sort(ele.begin(), ele.end());

        return ele;
    }

private:
    void midTraverse(TreeNode* node, vector<int>& vec)
    {
        if (node == nullptr)
            return;

        midTraverse(node->left, vec);
        vec.emplace_back(node->val);
        midTraverse(node->right, vec);
    }
};
// @lc code=end
