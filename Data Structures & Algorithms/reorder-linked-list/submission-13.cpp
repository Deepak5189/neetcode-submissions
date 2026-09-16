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
    void reorderList(ListNode* head) {
        // find middle
        ListNode* slow=head, * fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        // reverse the 2nd half
        ListNode* second=slow->next, * prev=nullptr;
        slow->next=nullptr;

        while(second){
            ListNode* temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }

        // merge the head and prev
        ListNode* first=head;
        second=prev;
        while(first && second){
            ListNode* firstNext=first->next;
            ListNode* secondNext=second->next;
            first->next=second;
            second->next=firstNext;

            first=firstNext;
            second=secondNext;
        }

    }
};
