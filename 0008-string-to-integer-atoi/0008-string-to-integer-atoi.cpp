class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        long long num = 0;

        // 1. Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        if (i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < s.size() && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        while (i < s.size()) {

            char ch = s[i];

            if (ch < '0' || ch > '9') {
                break;
            }

            num = num * 10 + (ch - '0');

            // 4. Check overflow
            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * num;
    }
};