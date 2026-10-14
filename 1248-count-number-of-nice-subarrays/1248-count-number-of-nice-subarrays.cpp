
class Solution {
public:
int odd(vector<int>& nums,int k){
 int n = nums.size();
        int i = 0;
        int j=0;
        int count = 0;
        int oddcount=0;
        for(int j=0;j<n;j++){
            if(nums[j]%2!=0){
                oddcount++;
            }

        
        while(oddcount>k){
            if(nums[i]%2!=0){
                oddcount--;
            }
                i++;
            }
            count+=j-i+1;
        }
        return count;
        j++;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (odd(nums,k) - odd(nums,k-1));
       
    }
};
