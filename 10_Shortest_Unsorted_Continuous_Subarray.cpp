class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector <int> v=nums;
        sort(v.begin(),v.end());
        int low=0,high=nums.size()-1;
        while(low<high){
            if(nums[low]==v[low])
                low++;
            if(nums[high]==v[high])
                high--;
            else if(nums[low]!=v[low] && nums[high]!=v[high])
                break;
        }
        if(low>=high)
            return 0;
        return high-low+1;
    }
};
