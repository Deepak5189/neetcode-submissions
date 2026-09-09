class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(auto&c:s){
            if(isalnum(c)) s1+=tolower(c);
        }
        string s2="";
        reverse(s.begin(), s.end());
        for(auto&c:s){
            if(isalnum(c)) s2+=tolower(c);
        }
        
        return s1==s2;
    }
};
