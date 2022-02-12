/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (41.33%)
 * Likes:    7509
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;


        // promote
        int res = 0;
        while (p1->next != NULL && p2->next != NULL) {
            int nodeVal = p1->val + p2->val + res;
            if (nodeVal > 9) {
                nodeVal -= 10;
                res = 1;
            } else 
                res = 0;
            
            p1->val = nodeVal;
            p2->val = nodeVal;

            p1 = p1->next;
            p2 = p2->next;
        }


        // l1 longer
        if (p1->next != NULL) {
            int lastVal = p1->val + p2->val + res;
            if (lastVal > 9) {
                p1->val = lastVal - 10;
                res = 1;
            } else {
                p1->val = lastVal;
                res = 0;
            }
            p1 = p1->next;

            while (p1->next != NULL) {
                int l1Val = p1->val + res;
                if (l1Val > 9) {
                    p1->val = l1Val - 10;
                    res = 1;
                } else {
                    p1->val = l1Val;
                    res = 0;
                }
                p1 = p1->next;
            }

            if (res) {
                int l1LastVal = p1->val + res;
                if (l1LastVal > 9) {
                    p1->val = 0;
                    p1->next = new ListNode(1);
                } else 
                    p1->val = l1LastVal;
            }

            return l1;
        }

        // l2 longer
        if (p2->next != NULL) {
            int lastVal = p1->val + p2->val + res;
            if (lastVal > 9) {
                p2->val = lastVal - 10;
                res = 1;
            } else {
                p2->val = lastVal;
                res = 0;
            }
            p2 = p2->next;

            while (p2->next != NULL) {
                int l2Val = p2->val + res;
                if (l2Val > 9) {
                    p2->val = l2Val - 10;
                    res = 1;
                } else {
                    p2->val = l2Val;
                    res = 0;
                }
                p2 = p2->next;
            }

            if (res) {
                int l2LastVal = p2->val + res;
                if (l2LastVal > 9) {
                    p2->val = 0;
                    p2->next = new ListNode(1);
                } else 
                    p2->val = l2LastVal;
            }

            return l2;
        }

        // l1 & l2 is the same long
        int lastVal = p1->val + p2->val + res;
        if (lastVal > 9) {
            p1->val = lastVal - 10;
            p1->next = new ListNode(1);
        } else
            p1->val = lastVal;

        return l1;
    }
};
// @lc code=end

