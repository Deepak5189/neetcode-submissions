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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;

        ListNode* newhead=nullptr;
        while(head){
            ListNode* temp=head->next;
            head->next=newhead;
            newhead=head;
            // newhead->next=nullptr;
            head=temp;
        }
        return newhead;
    }
};
