class Solution {
public:
   int minelement(vector<int>& bloomDay){
    int n = bloomDay.size();
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
         mini = min(mini,bloomDay[i]);
    }
    return mini;
   }
   int maxelement(vector<int>& bloomDay){
    int n = bloomDay.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
         maxi = max(maxi,bloomDay[i]);
    }
    return maxi;
   }

   bool possible(vector<int>& bloomDay,int m,int k,int day){
    int count = 0;
    int n = bloomDay.size();
     int noofbouquet = 0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            count++;

        }
        else{
            noofbouquet+=(count/k);
            count = 0;

        }
    }
        noofbouquet+=(count/k);
        

    
    return noofbouquet>=m;
   };
   
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if((1LL*m*k)>n) return -1;
        int ans = -1;
        int low = minelement(bloomDay);
        int high = maxelement(bloomDay);
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;

            }
            else{
                
                low = mid+1;
            }
        }
        
        return ans;
    }
};