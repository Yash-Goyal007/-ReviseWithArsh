class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>& memo){
        if(i==dungeon.size()-1 && j==dungeon[0].size()-1) 
            return (dungeon[i][j]<=0)?1-dungeon[i][j]:1;
        if(i>=dungeon.size() || j>=dungeon[0].size()) 
            return 1e9;
        if(memo[i][j]!=1e9) 
            return memo[i][j];
        int right = solve(i,j+1,dungeon,memo);
        int down = solve(i+1,j,dungeon,memo);
        int health = min(right,down) - dungeon[i][j];
        memo[i][j] = health<=0?1:health;
        return memo[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> memo(m+1,vector<int>(n+1,1e9));
        return solve(0,0,dungeon,memo);
    }
};
