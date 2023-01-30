class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(auto it:left)
            mx = max(it,mx);
        for(auto it:right)
            mn = min(it,mn);
        return max(mx,n-mn);
    }
};
