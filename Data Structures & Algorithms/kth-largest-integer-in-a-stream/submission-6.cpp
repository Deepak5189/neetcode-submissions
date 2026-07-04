class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        int i=0;
        this->k=k;
        while(i<k && i<nums.size()){
            min_heap.push(nums[i++]);
        }
        for(;i<nums.size();i++){
            min_heap.push(nums[i]);
            if(min_heap.size()>this->k) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>this->k) min_heap.pop();
        return min_heap.top();
    }
};
