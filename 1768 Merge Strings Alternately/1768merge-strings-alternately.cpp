class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int n = word1.size();
        int m = word2.size();
        int maxLen = max(n, m);

        for(int i = 0; i < maxLen; i++) {
            if(i < n) {
                result += word1[i];
            }
            if(i < m) {
                result += word2[i];
            }
        }

        return result;
    }
        
    
};