class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
        
            if(letters[mid]>target){
                ans=mid;
               
                high=mid-1;
            }
            else{
               
                low=mid+1;
            }


        }
        if (ans == n) {
         return letters[0];
}       
        else {

         return letters[ans];
}
        
    }
};