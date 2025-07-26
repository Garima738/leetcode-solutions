class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
      
        int row=matrix.size();
        int cols=matrix[0].size();
           vector<vector<int>> result(cols, vector<int>(row));
        for(int i=0;i<row;i++){
            for(int j=0;j<cols;j++){
                result[j][i]=matrix[i][j];
            }
        }
        return result;
        
    }
};