class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        map<char,int> m;
        for(auto x:s)
            m[x]++;
        for(auto i:order){
            if(m.find(i)!=m.end()){
                while(m[i]--)
                    ans+=i; 
            }
        }
        m.clear();
        for(auto i:ans)
            m[i]++;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end())
                ans+=s[i];
        }
        return ans;
    }
};
