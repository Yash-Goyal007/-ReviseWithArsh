class Solution {
public:
    string getHint(string secret, string guess) {
        int left=0,right=0;
        map<int,int> m1,m2;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                left++;
            else
            {
                m1[secret[i]-'0']++;
                m2[guess[i]-'0']++;
            }
            
        }
        for(auto i:m1)
        {
            if(m2.find(i.first)!=m2.end())
            right+=min(m2[i.first],i.second);
        }
        string s="";
        s=to_string(left)+"A"+to_string(right)+"B";
        return s;
    }
};
