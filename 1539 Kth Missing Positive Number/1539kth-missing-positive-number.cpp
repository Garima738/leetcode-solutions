class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                k++;   // shift k forward
            } else {
                break;
            }
        }
        return k;
    }
};