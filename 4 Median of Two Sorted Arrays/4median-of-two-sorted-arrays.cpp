class Solution {
public:
vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> temp(m+n);

        int i=0, j=0, k=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                temp[k++] = nums1[i++];
            } else {
                temp[k++] = nums2[j++];
            }
        }

        while(i<m){
            temp[k++] = nums1[i++];
        }
        while(j<n){
            temp[k++] = nums2[j++];
        }

        return temp;  
    }




    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged = merge(nums1, nums2);
        int k=merged.size();
        if(k%2==1){
            return merged[k/2];

        }
        else {
            return (merged[k / 2 - 1] + merged[k/ 2]) / 2.0; 
        }

    }
};