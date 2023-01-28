class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        sort(piles.begin(),piles.end(),greater());
        for(int i=1;i<piles.size()- (piles.size()/3);i++)
            sum+=piles[i++];
        return sum;
    }
};
