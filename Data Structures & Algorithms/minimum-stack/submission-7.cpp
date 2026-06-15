class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        while(!st.empty()) st.pop();
    }
    
    void push(int val) {
        if(!st.empty()){
            int temp=min(st.top().second, val);
            st.push({val, temp});
        }else st.push({val, val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
