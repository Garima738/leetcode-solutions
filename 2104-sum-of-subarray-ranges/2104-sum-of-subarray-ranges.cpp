class Solution {
public:
    // Previous Greater
    vector<int> psmax(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> pge(n);

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                pge[i] = -1;
            }
            else {
                pge[i] = st.top();
            }

            st.push(i);
        }

        return pge;
    }

    // Next Greater
    vector<int> nsmax(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> nge(n);

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                nge[i] = n;
            }
            else {
                nge[i] = st.top();
            }

            st.push(i);
        }

        return nge;
    }

    // Previous Smaller
    vector<int> psmin(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> pse(n);

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }

    // Next Smaller
    vector<int> nsmin(vector<int>& nums, int n) {
        stack<int> st;
        vector<int> nse(n);

        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty()) {
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge = psmax(nums, n);
        vector<int> nge = nsmax(nums, n);
        vector<int> pse = psmin(nums, n);
        vector<int> nse = nsmin(nums, n);

        long long maximum = 0;
        long long minimum = 0;

        for(int i = 0; i < n; i++) {

            // Maximum contribution
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            maximum += (long long)nums[i] * leftMax * rightMax;

            // Minimum contribution
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            minimum += (long long)nums[i] * leftMin * rightMin;
        }

        return maximum - minimum;
    }
};