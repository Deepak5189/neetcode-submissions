class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        for(auto&n:nums1) arr.push_back(n);
        for(auto&n:nums2) arr.push_back(n);
        if(arr.size()<=1) return arr[0];
        sort(arr.begin(), arr.end());
        int mid=arr.size()/2;
        if(arr.size()%2==0){
            return double (arr[mid-1]+arr[mid])/2;
        }else return arr[mid];
    }
};
