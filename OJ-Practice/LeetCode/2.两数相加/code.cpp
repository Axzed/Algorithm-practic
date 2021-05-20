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
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        int t = 0;
       //循环遍历将两个链表里的val值全部先加起来先
        while(l1 || l2 || t){
            if(l1) t += l1 -> val, l1 = l1 -> next;
            if(l2) t += l2 -> val, l2 = l2 -> next;
            //在新的dummy单链表中依次取出加和值的个位放入该链表的当前节点
            cur -> next = new ListNode(t % 10);
           //后移一个节点放下一个数位
            cur = cur -> next;
            t /= 10;
        }
        return dummy -> next;
    }
};
