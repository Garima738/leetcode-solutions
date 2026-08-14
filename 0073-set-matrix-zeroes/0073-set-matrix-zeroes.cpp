class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]== 0){
        //             for(int col = 0;col<n;col++){
        //                 if(matrix[i][col]!=0){
        //                     matrix[i][col]=-1;
        //                 }
        //             }
        //             for(int row=0;row<m;row++){
        //                 if(matrix[row][j]!=0){
        //                     matrix[row][j]=-1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==-1){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }


        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(row[i]||col[j]){
                        matrix[i][j] = 0;
                    }

                }
            }
        
       // return matrix;
    }
};