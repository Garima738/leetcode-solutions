class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freqT(128, 0);
        vector<int> windowfreq(128, 0);

        for(char c : t) {
            freqT[c]++;
        }

        int i = 0;
        int j = 0;

        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        while(j < s.length()) {

            windowfreq[s[j]]++;

         
            if(windowfreq[s[j]] <= freqT[s[j]]) {
                count++;
            }

            while(count == t.length()) {

                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                
                if(windowfreq[s[i]] <= freqT[s[i]]) {
                    count--;
                }

                windowfreq[s[i]]--;

                i++;
            }

            j++;
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};