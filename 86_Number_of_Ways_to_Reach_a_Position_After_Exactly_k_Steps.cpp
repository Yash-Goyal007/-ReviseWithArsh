class Solution {
    const int N = 1e9+7;
public:
    int nCr(int n, int r){
        if(r == 0) 
            return 1;
        vector<int> v(r+1,0);
        v[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=r; j>0; j--)
                v[j] = ((v[j] %N) + (v[j-1] %N)) %N;
        }
        return v[r];
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        int i = abs(endPos - startPos);
        if(i > k or i + k & 1) 
            return 0;
        long r = (i + k) / 2;
        return nCr(k,r);
    }
};
