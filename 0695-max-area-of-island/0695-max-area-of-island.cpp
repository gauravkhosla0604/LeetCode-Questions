class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j){
        int rows=grid.size();
        int cols=grid[0].size();

        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int area=1;

        area+=dfs(grid,i-1,j);
        area+=dfs(grid,i+1,j);
        area+=dfs(grid,i,j-1);
        area+=dfs(grid,i,j+1);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int maxArea=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int currArea=dfs(grid,i,j);
                    maxArea=max(maxArea,currArea);
                }
            }
        }
        return maxArea;
    }
};