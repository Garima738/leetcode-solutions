class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

     
        for(char ch : s) {
            freq[ch]++;
        }

        int length = 0;
        bool oddFound = false;

        for(auto it : freq) {
            int count = it.second;

            if(count % 2 == 0) {
                length += count;
            } else {
                length += count - 1;
                oddFound = true;
            }
        }

        
        if(oddFound) {
            length += 1;
        }

        return length;
    }
};