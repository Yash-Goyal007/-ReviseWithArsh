class Solution {
public:
    bool backtrack(vector<int>& nums,vector<int>& v, int target, int sum, int i, int k) {
        if (k == 0) 
            return true;
        if (sum == target) 
            return backtrack(nums, v, target, 0, 0, k-1);
        for (int j = i; j < nums.size(); j++){
            if (v[j] || sum + nums[j] > target) 
                continue;
            v[j] = true;
            if (backtrack(nums, v, target, sum + nums[j], j+1, k)) 
                return true;
            v[j] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) 
            return false;
        vector<int> v(nums.size(), false);
        return backtrack(nums, v, sum / k, 0, 0, k);
    }
};
