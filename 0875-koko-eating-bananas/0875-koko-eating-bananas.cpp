class Solution {
public:
  int maxelement(vector<int>& piles){
  int n= piles.size();
  int maxi = INT_MIN;
  for(int i=0;i<n;i++)

{
    maxi = max(maxi,piles[i]);

}  
return maxi ;
  }

  long long calculatehours(vector<int>& piles ,int hours){
    long long totalhours = 0;
    int n= piles.size();
    for(int i=0;i<n;i++){
        totalhours += ceil((double(piles[i]))/(double(hours)));

    }
    return totalhours;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int n= piles.size();
    int low = 1;
    int high  = maxelement(piles);
    int ans =1;
    while(low<=high){
        int mid = (low+high)/2;
         long long totalhours = calculatehours(piles,mid);
        if(totalhours<=h){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    } 
    return low;
        
    }
};