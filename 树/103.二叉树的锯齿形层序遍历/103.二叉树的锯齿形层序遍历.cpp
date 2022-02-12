/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.26%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    226.2K
 * Total Submissions: 395K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[20,9],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> level;
        level.push(root);
        int size = 1;
        bool flag = true;

        vector<vector<int>> zigzag;
        while (size != 0) {
            vector<int> zz;
            vector<TreeNode*> nodes;
            for (int i = 0; i < size; i++) {
                auto node = level.front();
                nodes.emplace_back(node);
                level.pop();
                if (node->left != nullptr) {
                    level.push(node->left);
                }
                if (node->right != nullptr) {
                    level.push(node->right);
                }
            }

            if (flag) {
                auto iter = nodes.begin();
                while (iter != nodes.end()) {
                    zz.emplace_back((*iter)->val);
                    iter++;
                }
            } else {
                auto iter = nodes.rbegin();
                while (iter != nodes.rend()) {
                    zz.emplace_back((*iter)->val);
                    iter++;
                }
            }

            flag = !flag;
            zigzag.emplace_back(zz);
            size = level.size();
        }

        return zigzag;
    }
};
// @lc code=end

