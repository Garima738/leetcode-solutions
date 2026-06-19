class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int altitude=0;
        int maxaltitude=0;
        for(int i=0;i<n;i++){
            altitude+=gain[i];
        
       if( maxaltitude<altitude){
     maxaltitude=altitude;
       }}
       return maxaltitude;
    }
};