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
        if(head==NULL || head->next == NULL) return head;
        ListNode* h2=new ListNode(head->val);
        ListNode* temp=head->next;
        while(temp!=NULL){
            ListNode* t=new ListNode(temp->val);
            t->next=h2;
            h2=t;
            temp=temp->next;
        }
        return h2;
    }
};
