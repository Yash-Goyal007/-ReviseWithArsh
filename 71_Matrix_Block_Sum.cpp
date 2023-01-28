class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int> > dp(mat.size()+1,vector<int>(mat[0].size()+1,0));
        for (int i = 1; i < dp.size(); i++){
            for (int j = 1; j < dp[0].size(); j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                int m=mat.size();
                int n=mat[i].size();
                int temp1=max(0,i-k)+1;
                int temp2=max(0,j-k)+1;
                int temp3=min(i+k+1,m);
                int temp4=min(j+k+1,n);
                ans[i][j]=dp[temp3][temp4]+dp[temp1-1][temp2-1]-dp[temp1-1][temp4]-dp[temp3][temp2-1];
            }
        }
        return ans;
    }
};
