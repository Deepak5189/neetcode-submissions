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
        if(!head || !head->next) return;

        stack<ListNode*> st;
        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int k=st.size()/2;
        ListNode* cur=head;
        while(k--){
            ListNode* rev=st.top();
            st.pop();
            ListNode* temp=cur->next;
            cur->next=rev;
            rev->next=temp;
            cur=temp;
        }
        cur->next=NULL;
        return;
    }
};
