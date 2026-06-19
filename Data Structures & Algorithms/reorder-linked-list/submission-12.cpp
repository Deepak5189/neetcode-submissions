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
    ListNode* cur;
    void solve(ListNode* head){
        if(!head) return;
        solve(head->next);
        ListNode* temp=cur->next;
        if(!cur->next){
            return;
        } else if(cur==head){
            cur->next=NULL;
            return;
        }
        cur->next=head;
        head->next = (temp==head)?NULL:temp;
        cur=temp;
    }

    void reorderList(ListNode* head) {
        cur=head;
        solve(head);
    }
};
