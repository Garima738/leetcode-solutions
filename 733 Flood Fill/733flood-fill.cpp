class Solution {
public:
    
    void dfs(int r, int c, vector<vector<int>>& image, int oldColor, int newColor) {
        
       
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
            return;
       
        if (image[r][c] != oldColor)
            return;
       
        image[r][c] = newColor;
      
        dfs(r+1, c, image, oldColor, newColor); // down
        dfs(r-1, c, image, oldColor, newColor); // up
        dfs(r, c+1, image, oldColor, newColor); // right
        dfs(r, c-1, image, oldColor, newColor); // left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];
        if (oldColor == color)
            return image;
        
        dfs(sr, sc, image, oldColor, color);
        return image;
    }
};
