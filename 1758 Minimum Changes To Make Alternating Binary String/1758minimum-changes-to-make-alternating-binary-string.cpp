class Solution {
public:
    int minOperations(string s) {
        int count0 = 0;

        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] != '0') count0++;
            if(i % 2 == 1 && s[i] != '1') count0++;
        }

        return min(count0, (int)s.size() - count0);
    }
};