class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string s ="";
       string t ="";
       for(int i=0;i<word1.size();i++){
        s+=word1[i];

       }
       for(int j=0;j<word2.size();j++){
        t += word2[j];

       }

       
        return s==t;
      
       

        
        
        
    }

    
};