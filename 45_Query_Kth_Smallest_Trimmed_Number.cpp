class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries){
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<nums.size();i++){
                int temp=nums[i].length()-x[1];
                string s=nums[i].substr(temp,x[1]);
                if(pq.size()<x[0])
                    pq.push({s,i});
                else{
                    if(pq.top().first > s){
                        pq.pop();
                        pq.push({s,i});
                    }
                }
            }
            int val=pq.top().second;
            ans.push_back(val);
        }
        return ans;
    }
};
