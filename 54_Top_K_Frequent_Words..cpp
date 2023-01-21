class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>hash;
        for(int i=0; i<words.size(); i++)
            hash[words[i]]++;
        priority_queue<pair<int, string>>pq;
        for(auto &i: hash){
            pq.push(make_pair(-i.second, i.first));
            if(pq.size() > k)
                pq.pop();
        }
        vector<pair<int, string>>v;
        while(!pq.empty()){
            v.emplace_back(pq.top());
            pq.pop();
        }
        sort(v.begin(), v.end());
        vector<string>ans;
        for(int i=0; i<v.size(); i++)
            ans.push_back(v[i].second);
        return ans;
    }
};
