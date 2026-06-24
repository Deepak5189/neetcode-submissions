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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st;
        ListNode* node=head;
        while(node){
            st.push(node);
            node=node->next;
        }
        ListNode* last;
        while(n--){
            last=st.top();
            st.pop();
        }
        if(st.empty()){
            head=head->next;
            return head;
        }
        st.top()->next=last->next;
        last=NULL;

        return head;
    }
};
