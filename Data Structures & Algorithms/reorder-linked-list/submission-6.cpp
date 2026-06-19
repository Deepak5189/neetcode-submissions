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
    ListNode* reverseList(ListNode* node){
        if(!node || !node->next){
            return node;
        }

        ListNode* last=reverseList(node->next);
        node->next->next = node;
        node->next=NULL;
        return last;  
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* slow=head,* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* cur=head,* rev=reverseList(slow);

        while(rev->next){
            ListNode* tempcur=cur->next;
            cur->next=rev;
            ListNode* temprev=rev->next;
            rev->next=tempcur;
            cur=tempcur;
            rev=temprev;
        }
        return;
    }
};
