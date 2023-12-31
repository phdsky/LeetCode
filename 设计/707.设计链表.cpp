/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (32.78%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    86.7K
 * Total Submissions: 263.8K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 *
 * 在链表类中实现这些功能：
 *
 *
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 *
 *
 *
 *
 * 示例：
 *
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 *
 *
 */

// @lc code=start

/**
 * 单链表设计
 */
// C++单向链表模板
class MyLinkedList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(nullptr)
        {
        }
    };
    ListNode *head;

public:
    MyLinkedList() :
        head(nullptr)
    {
    }

    // 获得链表中第index个节点的值
    int get(int index)
    {
        int i = 0;
        ListNode *p = head;
        while (p && i < index)
        {
            p = p->next;
            i++;
        }
        if (p)
            return p->val;
        else
            return -1;
    }

    // 在链表头部插一个值为val的节点
    void addAtHead(int val)
    {
        ListNode *p = new ListNode(val);
        p->next = head;
        head = p; // 更换头节点
    }

    // 在链表尾部添加一个值为val的节点
    void addAtTail(int val)
    {
        ListNode *p = new ListNode(val);
        // 链表为空，直接将新节点作为头节点
        if (head == nullptr)
        {
            head = p;
            return;
        }
        ListNode *q = head;
        // 遍历直到q的next节点为空
        while (q->next)
        {
            q = q->next;
        }
        q->next = p;
    }

    // 在索引为index的节点之前添加值为val的节点
    void addAtIndex(int index, int val)
    {
        ListNode *node = new ListNode(val);
        // 1、index小于等于0，直接在头部插入节点
        if (index <= 0)
        { // 若index小于等于0，我们仅需要在头节点前面插入新节点就行了
            // 注意这里不能使用指针p，因为p=node时，p所指向的地址发生了变化，head指向的地址没有变化，所以我们这里要使用指针head
            node->next = head;
            head = node;
            return;
        }
        int i = 0;
        ListNode *p = head;
        // 在索引为index的节点之前插入新节点，我们需要找到它的前驱节点，然后插入在它的前驱节点后面
        while (p && i < index - 1)
        {
            p = p->next;
            ++i;
        }
        // 2、p为索引节点的前驱节点
        if (p)
        {
            node->next = p->next;
            p->next = node;
        }
    }

    // 删除索引为index的节点
    void deleteAtIndex(int index)
    {
        // 1、index为0，我们直接删除head节点
        if (index == 0 && head != nullptr)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
            return;
        }
        int i = 0;
        ListNode *p = head;
        // 删除索引为index的节点，我们需要找到它的前驱节点p，p->next为需要删除节点
        while (p && i < index - 1)
        {
            p = p->next;
            i++;
        }
        // 2、index超过链表范围，删除失败
        if (!p) return;
        // 3、index的位置合法，我们找到需要删除的p->next节点
        if (p->next)
        {
            ListNode *del = p->next;
            p->next = del->next;
            delete del;
        }
    }

    int length()
    {
        int i = 0;
        ListNode *p = head;
        while (p)
        {
            i++;
            p = p->next;
        }
        return i;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
