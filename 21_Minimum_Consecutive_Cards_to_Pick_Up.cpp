class Solution {
    int N=1e9+7;
public:
    int minimumCardPickup(vector<int>& cards) {
        vector <pair<int,int>> v;
        for(int i=0;i<cards.size();i++)
            v.push_back({cards[i],i});
        sort(v.begin(),v.end());
        int ans=N;
        for(int i=1;i<cards.size();i++){
            if(v[i].first==v[i-1].first)
                ans=min(ans,abs(v[i].second - v[i-1].second +1));
        }
        return ans==N?-1:ans;
    }
};
