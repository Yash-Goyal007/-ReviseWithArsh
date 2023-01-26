class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
		vector<int> dis(n + 1,1e9);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		for(auto i : times){
			int x = i[0];
			int y = i[1];
			int z = i[2];
			adj[x].push_back({y,z});
		}
		dis[0]=-1e9;
		dis[k] = 0;
		pq.push({0,k});
		while(!pq.empty()){
			int temp1 = pq.top().second;
			int temp2 = pq.top().first;
			pq.pop();
			for(auto i : adj[temp1]){
				int x = i.first;
				int y = i.second;
				if(temp2 + y < dis[x]){
					dis[x] = temp2 + y;
					pq.push({dis[x],x});
				}
			}
		}
		for(auto i : dis)
			if(i==1e9) return -1;
		return *max_element(dis.begin(),dis.end());
    }
};
