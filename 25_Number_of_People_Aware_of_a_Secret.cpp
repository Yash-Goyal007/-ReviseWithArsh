class Solution {
    int N=1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<long long int, long long int> mp1,mp2;
        mp1[1+delay] = 1;
        mp2[1+forget] = 1;
        long long int temp = 0,ans = 0;
        for(int i = 1 + delay; i <= n; ++ i){
            temp += mp1[i] % N;
            temp -= mp2[i] % N; 
            mp1[i + delay] += temp; 
            mp2[i + forget] += temp;  
        }
        for(auto i: mp2)
            if(i.first > n) ans += i.second;
        return ans % N;
    }
};
