/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (63.38%)
 * Likes:    868
 * Dislikes: 0
 * Total Accepted:    168.9K
 * Total Submissions: 266.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * 请将其重新排列后变为：
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 *
 *
 *
 * 提示：
 *
 *
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * 辅助容器
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return;
        }

        vector<ListNode *> nodeVector;
        ListNode *node = head;
        while (nullptr != node)
        {
            nodeVector.push_back(node);
            node = node->next;
        }

        int size = nodeVector.size();
        int i = 0;
        for (; i < size / 2; ++i)
        {
            nodeVector[i]->next = nodeVector[size - 1 - i];
            nodeVector[size - 1 - i]->next = nodeVector[i + 1];
        }
        nodeVector[i]->next = nullptr;

        return;
    }
};
// @lc code=end
