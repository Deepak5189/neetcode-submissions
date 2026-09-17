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
        // traverse every first node of all the lists and put it inside a min heap
        struct Compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val>b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
        for(auto&pt:lists){
            if(pt) min_heap.push(pt);
            // pt=pt->next;
        }
        if(min_heap.empty()) return nullptr;

        // take the first node from min heap
        ListNode head;
        ListNode* cur=&head;
        while(!min_heap.empty()){
            ListNode* node=min_heap.top();
            min_heap.pop();
            cur->next=node;
            cur=cur->next;
            if(node->next) min_heap.push(node->next);
        }

        return head.next;

        // add the smallest node from the existing pointers of the lists
        
        // let's say there are m lists each with n nodes; so, step 1: o(m*log(m)); step 2: o(log(m)); step 3: o(m+log(m));
        // step 1 happens only once but step 2 and 3 happens every cycle so
    }
};
