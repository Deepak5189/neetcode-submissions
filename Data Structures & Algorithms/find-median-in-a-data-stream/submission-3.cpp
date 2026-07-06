class MedianFinder {
public:
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
    MedianFinder() {
        // 
    }
    
    void addNum(int num) {
        if(lq.empty() || num<=lq.top()){
            lq.push(num);
        }else if(rq.empty() || num>rq.top()){
            rq.push(num);
        }else{
            lq.push(num);
        }

        if(rq.size()>lq.size()){
            lq.push(rq.top());
            rq.pop();
        }
        if(lq.size()-rq.size()>1){
            rq.push(lq.top());
            lq.pop();
        }
    }
    
    double findMedian() {
        if((lq.size()+rq.size())%2==0){
            return (lq.top()+rq.top())/2.0;
        }else{
            return (double) lq.top();
        }
    }
};
