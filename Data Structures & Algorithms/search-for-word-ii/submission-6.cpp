class Solution {
public:
    unordered_map<char, vector<pair<int, int>>> mp;
    bool isValid(string& word, int idx, vector<vector<char>>& board, pair<int, int> p, vector<vector<bool>>& visited_locs){
        if(idx==word.size()){
            return true;
        }
        int row=p.first, col=p.second;
        if(row<0 || col<0 || row>=board.size() || col>=board[row].size() || visited_locs[row][col]==true || word[idx]!=board[row][col]) return false;
        visited_locs[row][col]=true;
        if(
            isValid(word, idx+1, board, {row-1, col}, visited_locs) || 
            isValid(word, idx+1, board, {row+1, col}, visited_locs) ||
            isValid(word, idx+1, board, {row, col-1}, visited_locs) ||
            isValid(word, idx+1, board, {row, col+1}, visited_locs)
        ) return true;
        visited_locs[row][col]=false;
        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        unordered_set<string> st;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                mp[board[i][j]].push_back({i, j});
            }
        }
        for(auto& word: words){
            if(mp.find(word[0])==mp.end()) continue;
            vector<vector<bool>> visited_locs(board.size(), vector<bool>(board[0].size(), false));
            for(auto p:mp[word[0]]){
                if(isValid(word, 0, board, p, visited_locs)){
                    if(st.count(word)>0) continue;
                    st.insert(word);
                    ans.push_back(word);
                }
            }
            
        }
        return ans;
    }
};
