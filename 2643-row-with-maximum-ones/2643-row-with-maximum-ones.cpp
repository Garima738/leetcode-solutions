class Solution {
public:
    int lowerbound(vector<int>& arr,int n,int x){
        int low = 0;
        int high = n-1;
        int ans =n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){
                ans =  mid;
                high = mid-1;

            }
            else{
                low = mid+1;
            }
           
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxones = -1;
        int index = -1;
        for(int i=0;i<n;i++){
          sort(mat[i].begin(), mat[i].end());
            int countones = m-lowerbound(mat[i],m,1);
            if(countones>maxones){
                maxones=countones;
                index = i;

            }


        }
        return {index,maxones};


        
    }
};