class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int size=m+n;
        int i=0, j=0, k=0, lval=-1, rval=-1;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                if(k==(size/2)-1) lval=nums1[i];
                if(k==(size/2)) rval=nums1[i];
                i++;
            }else{
                if(k==(size/2)-1) lval=nums2[j];
                if(k==(size/2)) rval=nums2[j];
                j++;
            }
            k++;
        }

        while(i<m){
            if(k==(size/2)-1) lval=nums1[i];
            if(k==(size/2)) rval=nums1[i];
            i++;
            k++;
        }
        while(j<n){
            if(k==(size/2)-1) lval=nums2[j];
            if(k==(size/2)) rval=nums2[j];
            j++;
            k++;
        }

        if(size%2 ==0) return (rval+lval)/2.0;
        return rval;
    }
};
