class Solution {
public:

   int maxelement(vector<int>& weights){
    int n = weights.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
         maxi = max(maxi,weights[i]);
    }
    return maxi;
   }
   int sum(vector<int>& weights){
    int n= weights.size();
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }

return sum;
   }
   int nodays(vector<int>& weights ,int capacity){
    int n = weights.size();
    int load = 0;
    int days = 1;
    for(int i = 0;i<n;i++){
        if((weights[i]+load)>capacity){
            days+=1;
            load = weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;

   }


    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = maxelement(weights);
        int high = sum(weights);
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            int noofdays = nodays(weights,mid);
            if(noofdays<=days){
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