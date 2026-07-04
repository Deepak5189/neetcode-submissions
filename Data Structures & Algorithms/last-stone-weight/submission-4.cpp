class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        for(auto& n: stones) max_heap.push(n);

        while(max_heap.size()>1){
            int s1=max_heap.top(); max_heap.pop();
            int s2=max_heap.top(); max_heap.pop();
            if(abs(s1-s2)>0) max_heap.push(abs(s1-s2));
        }
        return max_heap.size()==0?0:max_heap.top();
    }
};
