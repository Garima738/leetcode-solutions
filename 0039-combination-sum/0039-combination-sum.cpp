class Solution {
public:
void combination(int index,vector<int>& ds,vector<int>& candidates,vector<vector<int>>& ans,int target){
    int n = candidates.size();
    if(index == n){
        if(target==0){
           // ds.push_back9arr[index];
            ans.push_back(ds);
        }
        return;

    }
    if(candidates[index]<=target){
    ds.push_back(candidates[index]);
    combination(index,ds,candidates,ans,target-candidates[index]);
    ds.pop_back();
    }
    combination(index+1,ds,candidates,ans,target);

}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
   combination(0,ds,candidates,ans,target);
   return ans;

    }
};