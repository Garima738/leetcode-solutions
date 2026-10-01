class Solution {
public:
void combination(int index,vector<int>& ds, vector<vector<int>>& ans,int target,vector<int>& candidates){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i = index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]<=target) {
            ds.push_back(candidates[i]);
            combination(i+1,ds,ans,target-candidates[i],candidates);
            ds.pop_back();
        
    }
    }
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        combination(0,ds,ans,target,candidates);
        return ans;
    }
};