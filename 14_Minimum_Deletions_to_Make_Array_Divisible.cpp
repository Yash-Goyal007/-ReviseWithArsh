class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());
        int count=0;
        int temp=numsDivide[0];
        for(int i=1; i<numsDivide.size(); i++){
            temp=__gcd(temp, numsDivide[i]);
        }
        if(nums[0]>temp){return -1;}
        for(int i=0; i<nums.size(); i++){
            if(temp%nums[i]==0){
                return count;
            }
            count++;
        }
        return -1;
    }
};
