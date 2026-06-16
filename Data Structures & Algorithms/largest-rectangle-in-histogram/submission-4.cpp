class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxa=0, i=0;
        for(;i<heights.size();i++){
            int startind=i;
            while(!st.empty() && st.top().second>heights[i]){
                auto&[f, s]=st.top();
                st.pop();
                maxa=max(maxa, s*(i-f));
                startind=min(startind, f);
            }
            st.push({startind, heights[i]});
        }

        while(!st.empty()){
            auto&[f, s]=st.top();
            st.pop();
            maxa=max(maxa, s*(i-f));
        }
        return maxa;
    }
};
