class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> m;
        for(auto i:rectangles){
            m[{i[0],i[1]}]++;
            m[{i[2],i[3]}]++;
            m[{i[0],i[3]}]--;
            m[{i[2],i[1]}]--;
        }
        int count=0;
        for( auto i=m.begin();i!=m.end();i++){
            if(abs(i->second)==1){
                count++;
            }
            else if(abs(i->second)!=1&&i->second!=0){
                return false;
            }
        }
        return count==4;
    }
};
