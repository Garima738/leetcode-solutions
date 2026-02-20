class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {

        int n= nums.size();
        vector<int>even;
        vector<int>odd;


        for(int i=0;i<n;i++ ){
            if(i%2==0){
                even.push_back(nums[i]);
                
            }
             
        }

             for(int i=0;i<n;i++ ){
            if(i%2!=0){
                odd.push_back(nums[i]);
            }
             }
              sort(even.begin(), even.end());

               sort(odd.begin(), odd.end(), greater<int>());
              vector<int>result(n);
               int e = 0;
               int o = 1;
               for(int i=0;i<even.size();i++){
                result[e]=even[i];
                e+=2;
               }
  for(int i=0;i<odd.size();i++){
                result[o]=odd[i];
                o+=2;
  }
               return result;

    }
};