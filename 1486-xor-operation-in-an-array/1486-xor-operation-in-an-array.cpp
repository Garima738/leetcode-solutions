class Solution {
public:
    int xorOperation(int n, int start) {
        
        vector<int>arr(n);
        int xori = 0;
        for(int i=0;i<n;i++){
        arr[i] = start+2*i;
        arr.push_back(arr[i]);


        
        xori = xori^arr[i];

        }
    return xori ;
    }
};