/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 *
 * https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (62.91%)
 * Likes:    524
 * Dislikes: 0
 * Total Accepted:    122K
 * Total Submissions: 192.6K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * 给定一个二叉树
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 
 * 初始状态下，所有 next 指针都被设置为 NULL。
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,7]
 * 输出：[1,#,2,3,#,4,5,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next
 * 指针连接），'#' 表示每层的末尾。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数小于 6000
 * -100 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* node = root;
        nodeVector.push_back(node);
        levelVector.push_back(1);

        int id = 0;
        while (id < nodeVector.size()) {
            if (nodeVector[id]->left != nullptr) {
                nodeVector.push_back(nodeVector[id]->left);
                levelVector.push_back(levelVector[id] + 1);
            }
            if (nodeVector[id]->right != nullptr) {
                nodeVector.push_back(nodeVector[id]->right);
                levelVector.push_back(levelVector[id] + 1);
            }

            ++id;
        }

        for (int i = 1; i < nodeVector.size() - 1; ++i) {
            if (levelVector[i] == levelVector[i + 1]) {
                nodeVector[i]->next = nodeVector[i + 1];
            }
        }

        return root;
    }

private:
    vector<Node*> nodeVector;
    vector<int> levelVector;
};
// @lc code=end

