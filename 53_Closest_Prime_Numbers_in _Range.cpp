class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v(right+1, 1);
        for(int i=2; i*i<=right; i++){
            if(v[i]==1){
                for(int j=i*i; j<=right; j+=i)
                    v[j]=0;
            }
        }
        vector<int> n;
        for(int i=max(2,left); i<=right; i++)
            if(v[i]==1) 
                n.push_back(i);
        int n1=-1, n2=-1, mn=1e8, diff;
        for(int i=1; i<n.size(); i++){
            diff = n[i]-n[i-1];
            if(diff < mn){
                mn = diff;
                n1 = n[i-1];
                n2 = n[i];
            }
        }
        return {n1,n2};
    }
};
