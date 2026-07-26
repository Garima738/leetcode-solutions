class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int n = nums.size();
//         int maxi = INT_MIN;
//         int product = 1;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
// for(int k=j+1;k<n;k++){
//     product = nums[i]*nums[j]*nums[k];
//     maxi = max(maxi,product);

// }

//             }
//         }
//         return maxi;
  sort(nums.begin(),nums.end());
  int p1 = nums[n-3]*nums[n-1]*nums[n-2];
  int p2 = nums[0]*nums[1]*nums[n-1];
  return max(p1,p2);

    }
};