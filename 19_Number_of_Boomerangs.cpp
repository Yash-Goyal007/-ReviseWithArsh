class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int temp=0;
        for (int i=0; i<points.size(); i++) {
            unordered_map<int,int> mp;
            for (int j=0; j<points.size(); j++) {
                int x = points[i][0]-points[j][0];
                int y = points[i][1]-points[j][1];
                temp+=(mp[(x*x+y*y)]++)*2;
            }
        }
        return temp;
    }
};
