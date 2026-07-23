class Solution {
public:

    int findPivot(vector<int>&nums,int n){
        
        int start=0;
        int end=n-1;
        while(start<end){ 
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[end]){
                start=mid+1;
            }
            else{
                end=mid;
            }   
        }
        return end;
    }

    int binarySearch(vector<int>&nums,int target,int low,int high){
       
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
               return mid;
            }
            else if(nums[mid]>target){
               high=mid-1;

            }
            else{
                
                 low=mid+1;
            }

        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot_index = findPivot(nums,n);
        int idx = binarySearch(nums,target,0,pivot_index-1);
        if(idx!=-1)
        return idx;
         idx=binarySearch(nums,target,pivot_index,n-1);
        return idx;

    }
};



