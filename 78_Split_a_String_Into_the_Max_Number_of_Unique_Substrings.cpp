class Solution {
public:
    unordered_map<string,int> mp;
    int res=0;
    void solve(string s,int idx,string str,int ans){
        if(idx>=s.size()){
            res=max(res,ans);
            return;
        }
        str+=s[idx];
        if(mp[str]==0){
            mp[str]=1;
            ans++;
            solve(s,idx+1,"",ans);
            mp[str]=0;
            ans--;
        }
        solve(s,idx+1,str,ans);
    }

    int maxUniqueSplit(string s) {
        solve(s,0,"",0);
        return res;
    }
};
