class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
    //     unordered_map<char,int>mpp;
    //     int i=0;
    //     int j=0;
    //  int maxi =-1;
    //     while(j<n){
    //         mpp[s[j]]++;
    //         while(mpp[s[j]]>1){
    //             mpp[s[i]]--;
    //             if(mpp[s[i]]==0){
    //                 mpp.erase(s[i]);
                    
    //             }
    //             i++;
    //         }
          
        

    //   maxi = max(maxi,j-i+1);
    //     j++;
    //     }
    //   return maxi;
   // int n = s.length();
         int i=0;
         int j= 0;
         int maxi =0;
         unordered_map<char,int> mpp;
         while(j<n){
             mpp[s[j]]++;
            //  if(mpp.size()>j-i+1){
            //      j++;
            //  }
             if(mpp.size()==j-i+1){
                 maxi = max(maxi,j-i+1);
                 j++;
             }
             else if(mpp.size()<j-i+1){
                 while(mpp.size()<j-i+1){
                     mpp[s[i]]--;
                     if(mpp[s[i]]==0){
                         mpp.erase(s[i]);
                         
                     }
                     i++;
                 }
                 j++;
             }
        
         }
         return maxi;
        
    }
};