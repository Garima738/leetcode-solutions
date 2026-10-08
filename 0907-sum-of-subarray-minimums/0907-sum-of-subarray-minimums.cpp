class Solution {
public:

    vector<int> pge(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> p(n);

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[i] < nums[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                p[i] = -1;
            }
            else {
                p[i] = st.top();
            }

            st.push(i);
        }

        return p;
    }

    vector<int> nge(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> m(n);

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                m[i] = n;
            }
            else {
                m[i] = st.top();
            }

            st.push(i);
        }

        return m;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> p = pge(arr, n);
        vector<int> m = nge(arr, n);

        long long total = 0;

        for(int i = 0; i < n; i++) {

            int first = i - p[i];
            int second = m[i] - i;

            total += (long long)first * second * arr[i];
        }

        return total %1000000007;
    }
};