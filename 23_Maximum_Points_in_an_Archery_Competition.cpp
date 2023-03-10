class Solution {
public:
    void maximum_bob_points(const vector<int>& aliceArrows, vector<int>& result, vector<int> &curr,int& maxscore, int numArrows, int score=0, int k=11) {
        if(k == 0) {
            if(score > maxscore) {
                result = curr;
                result[0] = numArrows;
                maxscore = score;
            }
        } else {
            if(numArrows > aliceArrows[k]) {
                curr[k] = aliceArrows[k]+1;
                maximum_bob_points(aliceArrows, result, curr, maxscore, numArrows-aliceArrows[k] - 1, score + k, k-1);
            }
            curr[k]=0;
            maximum_bob_points(aliceArrows, result, curr, maxscore, numArrows, score, k-1);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> result(12), curr(12);
        int maxscore = 0;
        maximum_bob_points(aliceArrows, result, curr, maxscore, numArrows);
        return result;
    }
};


