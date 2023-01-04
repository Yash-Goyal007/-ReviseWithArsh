class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0, temp=0, res=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            temp+=i*nums[i];
        }
        res=temp;
        for(int i=nums.size()-1; i>=0; i--){
            temp+=sum-(nums[i]*nums.size());
            res=max(res, temp);
        }
        return res;
    }
};
