class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxh;
        int n = arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            maxh.push({abs(arr[i]-x),arr[i]});
        }
        while(maxh.size()>k){
            maxh.pop();
        }
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();

        }
         sort(ans.begin(),ans.end());
        return ans;
        
    }
};