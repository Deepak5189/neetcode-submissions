class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(target<matrix[mid][0]) j=mid-1;
            else i=mid+1;
        }
        int row=j;
        if(row<0) return false;
        i=0, j=matrix[row].size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(target==matrix[row][mid]) return true;
            if(target<matrix[row][mid]) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};
