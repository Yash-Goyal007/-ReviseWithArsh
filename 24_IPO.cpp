class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for(int i = 0; i < profits.size(); i++)
            v.push_back({capital[i], profits[i]});
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int ans = w,i=0;
        for(i = 0; i < profits.size() && v[i].first <= w; i++)
            pq.push(v[i].second);
        while(!pq.empty() && k){
            ans += pq.top();
            pq.pop();
            k--;
            while(i < profits.size() && v[i].first <= ans)
                pq.push(v[i].second), i++;            
        }
        return ans;
    }
};
