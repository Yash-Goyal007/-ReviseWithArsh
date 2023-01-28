class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size(), m = grid[0].size();
        int arr1[4] = {1, -1, 0, 0};
        int arr2[4] = {0, 0, -1, 1};
        int val = 0;
        pq.push({grid[0][0],{0,0}});
        grid[0][0] = -1;
        while(!pq.empty()){
            int j = pq.size();
            while(j--){
                pair<int, pair<int, int>> p = pq.top();
                int x = p.second.first, y = p.second.second;
                pq.pop();
                val = max(val, p.first);
                if(x == n-1 && y == m-1) 
                    return val;
                for(int i = 0; i < 4; i++){
                    int temp1 = x + arr1[i];
                    int temp2 = y + arr2[i];
                    if(temp1 < 0 || temp1 >= n || temp2 < 0 || temp2 >= m) continue;
                    if(grid[temp1][temp2] == -1) continue;
                    pq.push({grid[temp1][temp2],{temp1, temp2}});
                    grid[temp1][temp2] = -1;
                }
            }
        }
        return val;
    }
};
