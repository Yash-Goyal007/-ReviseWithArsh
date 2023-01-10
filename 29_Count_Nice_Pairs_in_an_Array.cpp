class Solution {
    int N=1e9+7;
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<long,long> mp;
        for(int i=0; i<nums.size();i++){
            long temp1 = nums[i],temp2=0;
            while(temp1!=0){
                temp2 = (10*temp2) + (temp1%10);
                temp1 = temp1/10;
            }
			  mp[nums[i] - temp2]++;
        }
        long ans=0;
        for(auto p:mp)
            ans = (ans +  (p.second*(p.second-1)/2)%N)%N;
        return ans;
    }
};
