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
    int removeNode(ListNode* head, int n){
        // 
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> stk;
        ListNode* node=head;
        while(node){
            stk.push(node);
            node=node->next;
        }
        ListNode* top=nullptr;
        while(n--){
            if(stk.empty()) return head;
            top=stk.top();
            stk.pop();
        }
        if(stk.empty()){
            return top->next;
        }
        stk.top()->next=top->next;
        return head;

    }
};
