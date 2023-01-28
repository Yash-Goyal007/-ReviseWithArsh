class Solution {
public:
    int distinctEchoSubstrings(string text) {
        if (text.size() <= 1) 
            return 0;
        int n = text.size();
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        unordered_set<string> res;
        string s = text;
        for (int j = n-1; j > 0; j--) {
            for (int i = j-1; i >= 0; i--) {
                dp[i][j] = s[i] == s[j] ? 1 + dp[i+1][j+1] : 0;
                if (dp[i][j] >= j-i) 
                    res.insert ( s.substr(i, j-i)); 
            }
        }
        return res.size();
    }
};
