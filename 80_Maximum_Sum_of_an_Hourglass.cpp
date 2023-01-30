class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int mx = 0;
        int m=grid.size(), n=grid[0].size();
        int sum;
        for(int i=0; i<=m-3; i++){
            for(int j=0; j<=n-3; j++){
                sum=0;
                for(int k=j; k<j+3; k++) {
                    sum += grid[i][k]; 
                    sum += grid[i+2][k]; 
                }
                sum += grid[i+1][j+1]; 
                mx = max(mx, sum); 
            }
        }
        return mx;
    }
};
