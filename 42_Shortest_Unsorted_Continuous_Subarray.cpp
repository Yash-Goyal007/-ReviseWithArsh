class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        for(int i=0)
        vector<int>v=nums;
        sort(v.begin(), v.end());
        int temp1=0, temp2=v.size()-1;
        while(temp1<=v.size()-1 && v[temp1]==nums[temp1])
            temp1++;
        while(temp2>=0 && v[temp2]==nums[temp2])
            temp2--;
        if(temp2<0 || temp1>v.size()-1)
            return 0;
        return temp2-temp1+1;
    }
};
