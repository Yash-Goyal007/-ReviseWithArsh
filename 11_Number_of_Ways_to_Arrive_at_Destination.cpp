class Solution {
    int mod = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n);
        for(auto &i: roads) {
            g[i[0]].push_back({i[1], i[2]});
            g[i[1]].push_back({i[0], i[2]});
        }
        vector<long long> dist(n, LONG_MAX);
        vector<int> path(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()) {
            pair<long long, int> t = pq.top();
            pq.pop();
            
            for(auto &nbr: g[t.second]) {
                long long vert = nbr.first;
                long long edge = nbr.second;
                
                if(dist[vert] > dist[t.second] + edge) {
                    dist[vert] = dist[t.second] + edge;
                    pq.push({dist[vert], vert});
                    path[vert] = path[t.second] %mod;
                }
                else if(dist[vert] == t.first + edge) {
                    path[vert] += path[t.second];
                    path[vert] %= mod;
                }
            }
        }
        
        return path[n-1];
    }
};
