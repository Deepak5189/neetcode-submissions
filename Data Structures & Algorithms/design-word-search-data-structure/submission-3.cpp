class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(auto&c:children) c=nullptr;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(auto w:word){
            int idx=w-'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node=node->children[idx];
        }
        node->isEnd = true;
    }

    bool solve(string word, TrieNode* node){
        if(word.size()==0) return node->isEnd;
        
        char c=word[0];
        if(c=='.'){
            bool res=false;
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    res=res || solve(word.substr(1, word.size()-1), node->children[i]);
                }
            }
            return res;
        }
        int idx=c-'a';
        if(node->children[idx]){
            return solve(word.substr(1, word.size()-1), node->children[idx]);
        }
        return false;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        return solve(word, node); 
    }
};
