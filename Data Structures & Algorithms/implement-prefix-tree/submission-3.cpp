class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(auto& c:children) c=nullptr;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(auto w: word){
            int idx=w-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(auto w:word){
            int idx=w-'a';
            if(!node->children[idx]){
                return false;
            }
            node=node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(auto p:prefix){
            int idx=p-'a';
            if(!node->children[idx]){
                return false;
            }
            node=node->children[idx];
        }
        return true;
    }
};
