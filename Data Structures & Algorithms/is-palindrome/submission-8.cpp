class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(auto&c:s){
            if(isalnum(c)) t+=tolower(c);
        }
        s=t;
        reverse(t.begin(), t.end());
        return s==t;
    }
};
