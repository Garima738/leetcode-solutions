class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                res.push_back(nums[i]);



            }
        }
        nums = res;                     
        return res.size(); 
        
    }
};