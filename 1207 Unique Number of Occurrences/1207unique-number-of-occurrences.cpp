class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
    sort(arr.begin(), arr.end());
    vector <int> count;
    int num = 1;
    int s = arr.size();

    for(int i = 0; i < s; i++) {
        if(i == s - 1) {
            count.push_back(num);
        } else {
            if(arr[i + 1] == arr[i]) {
                num++;
            } else {
                count.push_back(num);
                num = 1;
            }
        }
    }

    sort(count.begin(), count.end());
    for(int i = 0; i < count.size() - 1; i++) {
        if(count[i + 1] == count[i]) {
            return false;
        }
    }
    return true;
}
};