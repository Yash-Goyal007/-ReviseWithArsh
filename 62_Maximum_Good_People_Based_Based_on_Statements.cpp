class Solution {
public:
    int solve(vector<vector<int>>& statements,int temp,int n){
        int count = 0;
        for(int i=0;i<n;i++){
            if((temp & (1<<i))!=0){
                count++;
                for(int j=0;j<n;j++){
                    int mask=1<<j; 
                    if(((temp & mask)!=0 && statements[i][j]==0) || ((temp & mask)==0 && statements[i][j]==1))
                        return 0;
                }
            }
        }
		    return count;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        for(int i=0;i<(1<<statements.size());i++)
            ans=max(ans,solve(statements,i,statements.size()));
        return ans;
    }
};

    
