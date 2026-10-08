class Solution {
public:
   vector<int> prefixmax(vector<int>& height,int n){
    vector<int> prefix(n);
   prefix[0] = height[0];
    for(int i=1;i<n;i++){
        prefix[i] = max(prefix[i-1],height[i]);
    }

     return prefix;

    }
    vector<int> sufixmax(vector<int>& height,int n){
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] =max(suffix[i+1],height[i]);
        } 
        return suffix;

    }
    int trap(vector<int>& height) {
        int total = 0;
        int n = height.size();
       vector<int> prefix = prefixmax(height,n);
        vector<int> suffix = sufixmax(height,n);
        for(int i=0;i<n;i++){
       //  if(prefix<height[i] && suffix<height[i]){
         total = total + min(prefix[i],suffix[i])-height[i];
         }
         //}
         return total;
    }
};