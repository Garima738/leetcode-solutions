class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
           
           ans.push_back(nums[nums[i]]); 
        }
        return ans;
    }
};

//class Solution {
//public:
   // vector<int> buildArray(vector<int>& nums) {
        //int n = nums.size();
        //vector<int> ans(n);  // Pre-size the answer array
        
       // for(int i = 0; i < n; i++) {
         //   ans[i] = nums[nums[i]];
      //  }
        
       // return ans;
   // }
//};//
