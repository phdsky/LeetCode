/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (53.17%)
 * Likes:    785
 * Dislikes: 0
 * Total Accepted:    210.6K
 * Total Submissions: 396.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。
 *
 * 返回同样按升序排列的结果链表。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围 [0, 300] 内
 * -100
 * 题目数据保证链表已经按升序排列
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
 * 由于可能将头节点完全删除，因此需设置一个哨兵，接下来遍历删除重复节点即可
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);

        ListNode *curr = dummy;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            if (curr->next->val == curr->next->next->val)
            {
                int x = curr->next->val;
                while (curr->next != nullptr && curr->next->val == x)
                {
                    curr->next = curr->next->next;
                }
            }
            else
            {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end
