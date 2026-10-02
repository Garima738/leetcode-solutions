class Solution {
public:
     bool find(int i,int j,string& word,int index,vector<vector<char>>& board){
        if(index==word.length()){
            return true;

        }
        int m = board.size();
        int n = board[0].size();
      if(i<0 ||j<0||i>=m ||j>=n || board[i][j]=='$'){
        return false;
      }
      if(board[i][j]!=word[index]){
        return false;
      }
      char temp = board[i][j];
      board[i][j]='$';
      bool found = find(i+1,j,word,index+1,board)||find(i,j+1,word,index+1,board)||find(i-1,j,word,index+1,board)||find(i,j-1,word,index+1,board);
      board[i][j] = temp;
      return found;
      
           }

     bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(i,j,word,0,board))
                return true;
            }

        }
           return false;
        
    }
};