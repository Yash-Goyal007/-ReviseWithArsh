class Solution {
public:
    void dfs(int i,int j, vector<vector<int>> &grid,int &count,vector<vector<int>> & visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || visited[i][j]==1)
            return;
        count++;
        visited[i][j]=1;
        dfs(i-1,j,grid,count,visited);
        dfs(i,j+1,grid,count,visited);
        dfs(i,j-1,grid,count,visited);
        dfs(i+1,j,grid,count,visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid){
        int count=0;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int c=0;
                    dfs(i,j,grid,c,visited);
                    count=max(count,c);
                }
            }
        }
        return count;
    }
};
