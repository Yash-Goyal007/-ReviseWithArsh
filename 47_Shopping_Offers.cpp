class Solution {
    map<vector<int>, int> mp;
public:
    bool check(vector<int> need){
        for(int i = 0; i < need.size(); i++){
            if(need[i] < 0)
                return false;
        }
        return true;
    } 
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(mp[needs] > 0)
            return mp[needs];
        int mn = 0;
        for(int i = 0; i < needs.size(); i++)
            mn += needs[i] * price[i];   
        for(auto it : special){
            vector<int> temp = needs;
            for(int i = 0; i < temp.size(); i++)
                temp[i] -= it[i];
            if(check(temp))
                mn = min(mn, it[it.size() - 1] + shoppingOffers(price, special, temp));             
        }
        return mp[needs] = mn;
    }
};
