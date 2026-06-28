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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode*a, ListNode*b){
            return a->val>b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>,decltype(cmp)> minheap(cmp);

        for(auto&l:lists){
            if(l)minheap.push(l);
        }

        ListNode dummy(0);
        ListNode* cur=&dummy;

        while(!minheap.empty()){
            ListNode* smallest=minheap.top();
            minheap.pop();
            cur->next=smallest;
            cur=cur->next;

            if(smallest->next) minheap.push(smallest->next);
        }

        return dummy.next;
    }
};
