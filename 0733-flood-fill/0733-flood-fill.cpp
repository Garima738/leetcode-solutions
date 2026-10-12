class Solution {
public:
  void dfs(vector<vector<int>>& image, int sr,int sc,int color,int oldcolor){
     int n = image.size();
        int m = image[0].size();

        if(sr<0 || sc<0 ||sc>=m||sr>=n  ){
            return;

        }
        if(image[sr][sc]!=oldcolor){
            return;
        }

        image[sr][sc] = color;
        dfs(image,sr+1,sc,color,oldcolor);
        dfs(image,sr-1,sc,color,oldcolor);
        dfs(image,sr,sc+1,color,oldcolor);
        dfs(image,sr,sc-1,color,oldcolor);



  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        // int n = image.size();
        // int m = image[0].size();
        if(oldcolor == color){
            return image;
        }
        dfs(image,sr,sc,color,oldcolor);

        return image;

    }
};