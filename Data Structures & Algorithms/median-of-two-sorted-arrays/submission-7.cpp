class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int p1=0, p2=0;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]<=nums2[p2]) arr.push_back(nums1[p1++]);
            else arr.push_back(nums2[p2++]);
        }

        while(p1<nums1.size()) arr.push_back(nums1[p1++]);
        while(p2<nums2.size()) arr.push_back(nums2[p2++]);
        
        int mid=arr.size()/2;
        if(arr.size()%2==0){
            return double (arr[mid-1]+arr[mid])/2;
        }else{
            return double (arr[mid]);
        }
    }
};
