class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freq(26, 0);
        vector<int> windowfreq(26, 0);

        for(char c : p) {
            freq[c - 'a']++;
        }

        int k = p.size();
        int i = 0;
        int j = 0;

        vector<int> ans;

        while(j < s.length()) {

            windowfreq[s[j] - 'a']++;

            if(j - i + 1 < k) {
                j++;
            }

          
            else if(j - i + 1 == k) {

                if(freq == windowfreq) {
                    ans.push_back(i);
                }

                windowfreq[s[i] - 'a']--;
                i++;
                j++;
            }
        }

        return ans;
    }
};