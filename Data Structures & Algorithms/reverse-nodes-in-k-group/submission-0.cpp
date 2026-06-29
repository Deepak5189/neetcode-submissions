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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int>vals;
        int i=0;
        ListNode* node=head, * temp=head;
        while(temp){
            vals.push(temp->val);
            i++;
            temp=temp->next;

            if(i==k){
                while(!vals.empty()){
                    node->val=vals.top();
                    vals.pop();
                    node=node->next;
                }
                i=0;
            }
        }

        return head;
    }
};
