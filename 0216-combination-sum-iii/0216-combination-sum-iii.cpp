class Solution {
public:
 void combination(int k,int n,vector<vector<int>>& ans,vector<int>& ds,int index){
  if(ds.size() == k) {
    if(n == 0)
        ans.push_back(ds);

    return;
}
    for(int i = index;i<=9;i++){
        if(i>n) break;
        ds.push_back(i);
        combination(k,n-i,ans,ds,i+1);
        ds.pop_back();
    }

 }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>ds;
        combination(k,n,ans,ds,1);
        return ans;


        
    }
};