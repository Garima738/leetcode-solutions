class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        // Store next consonant index
        vector<int> nextConst(n);
        int lastIndex = n;

        for (int idx = n - 1; idx >= 0; idx--) {
            nextConst[idx] = lastIndex;

            if (!isVowel(word[idx])) {
                lastIndex = idx;
            }
        }

        unordered_map<char, int> mpp;
        int i = 0, j = 0, cons = 0;
        long long count = 0;

        while (j < n) {
            char ch = word[j];

            if (isVowel(ch)) {
                mpp[ch]++;
            } else {
                cons++;
            }

            while (cons > k) {
                char c = word[i];

                if (isVowel(c)) {
                    mpp[c]--;
                    if (mpp[c] == 0) {
                        mpp.erase(c);
                    }
                } else {
                    cons--;
                }

                i++;
            }

            while (mpp.size() == 5 && cons == k) {
                // Count valid extensions up to next consonant
                count += nextConst[j] - j;

                char c = word[i];

                if (isVowel(c)) {
                    mpp[c]--;
                    if (mpp[c] == 0) {
                        mpp.erase(c);
                    }
                } else {
                    cons--;
                }

                i++;
            }

            j++;
        }

        return count;
    }
};