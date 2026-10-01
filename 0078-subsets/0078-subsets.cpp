class Solution {
public:
void powerset(vector<int>& nums,vector<int>& ds,int index,vector<vector<int>>& ans){
    int n = nums.size();
    if(index==n){
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    powerset(nums,ds,index+1,ans);
    ds.pop_back();
    powerset(nums,ds,index+1,ans);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        powerset(nums,ds,0,ans);
        return ans;
       
      


        
    }
};