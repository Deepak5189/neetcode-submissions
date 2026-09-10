class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto&c:s){
            if(c=='(' || c=='{' || c=='['){
                stk.push(c);
            }else{
                if(stk.empty()) return false;
                char t=stk.top();
                stk.pop();
                if(c==')'){
                    if(t!='(') return false;
                }else if(c=='}'){
                    if(t!='{') return false;
                }else{
                    if(t!='[') return false;
                }
            }
        }
        return stk.empty();
    }
};
