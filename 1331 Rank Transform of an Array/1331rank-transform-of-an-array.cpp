class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(),temp.end());


        unordered_map<int,int>mpp;
        int rank = 1;
        for(int i=0;i<n;i++){
            if(mpp.find(temp[i])==mpp.end()){
                mpp[temp[i]]=rank;
                rank++;

            }
        }
        for(int i=0;i<n;i++){
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};