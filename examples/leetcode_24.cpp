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

 // Solution 1: change ListNodes themselves
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *first = head;
        if (first->next == nullptr) return head;
        ListNode *second = first->next;
        first->next = second->next;
        second->next = first;
        head = second;
        ListNode *third = second->next;
        while (1){
            if (first->next == nullptr) break;
            second = first->next;
            third = second->next;
            if (third == nullptr) break;
            first->next = third;
            second->next = third->next;
            third->next = second;
            first = second;
        }
        return head;
    }
};

// Solution 2: change vals of ListNodes.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *node = head;
        while (node){
            ListNode *nxt = node->next;
            if (not nxt) break;
            int tmp = node->val;
            node->val = nxt->val;
            nxt->val = tmp;
            node = nxt->next;
        }
        return head;
    }
};