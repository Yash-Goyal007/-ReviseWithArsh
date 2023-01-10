class Solution {
public:
    int check(vector<vector<int>>& st,int arragment,int n){
        int count=0;
        for(int i=0;i<n;i++){
            if((arragment & (1<<i))!=0){
                count++;
                for(int j=0;j<n;j++){
                    int mask=1<<j; 
                    if(((arragment & mask)!=0 && st[i][j]==0) || ((arragment & mask)==0 && st[i][j]==1))
                        return 0;
                }
            }
        }
		return count;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int ans=0;
        for(int i=0;i<(1<<statements.size());i++)
            ans=max(ans,check(statements,i,statements.size()));
        return ans;
    }
};

    
