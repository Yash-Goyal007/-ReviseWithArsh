class Solution {
    vector<vector<int>> res;
public:
     void temp(int i,vector<int> &v1,vector<int> &v2,int n,int k)
    {
        if(i>=v1.size())
        {
            if(v2.size()==k and n==0)
            {
                res.push_back(v2);
            }
            return;
        }
        if(v1[i]<=n)
        {
            v2.push_back(v1[i]);
            temp(i+1,v1,v2,n-v1[i],k);
            v2.pop_back();
        }
        temp(i+1,v1,v2,n,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v1,v2;
        int x=1;
        for(int i=1;i<=9;i++) v1.push_back(i);
        temp(0,v1,v2,n,k);
        return res;
    }
};
