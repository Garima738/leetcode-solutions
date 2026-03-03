class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }
        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0) continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> temp = freq;
            temp[a]--;
            temp[b]--;
            temp[c]--;

            if (temp[a] >= 0 && temp[b] >= 0 && temp[c] >= 0) {
                result.push_back(num);
            }
        }

        return result;
    }
};