class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,unsigned long long> mp;
        unordered_map<string,pair<string,unsigned long>> mx;
        vector<vector<string>> ans;
        unsigned long  view=0;
        int n=creators.size();
        for(int i=0;i<n;i++){
            mp[creators[i]]=mp[creators[i]]+views[i];
            if(view<mp[creators[i]])
                view=mp[creators[i]];
            if(mx.find(creators[i])==mx.end())
                mx[creators[i]]=make_pair(ids[i],views[i]);
            else if(mx[creators[i]].second<views[i])
                mx[creators[i]]=make_pair(ids[i],views[i]);
            else if(mx[creators[i]].second==views[i]){
                if(mx[creators[i]].first>ids[i])
                   mx[creators[i]].first=ids[i]; 
            }

        }
        for(auto i:mp){
            if(view==i.second)
                ans.push_back({i.first,mx[i.first].first});
        }
        return ans;
    }
};
