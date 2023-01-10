class Solution {
public:
    int magicalString(int n) {
        if (n < 2) 
            return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        int res = 1;
        int end = 1;
        int j = 0;
        for (int i = 3; i <= n; i++) {
            if (end < i) 
                end += dp[++j+1];
            dp[i] = j % 2 + 1;
            if (j % 2 == 0)
                res++;
        }
        return res;
    }
};
