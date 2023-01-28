class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string>s;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int count = 0;
            string str = "";
            for(int j = i;j<n;j++){
                str += nums[j]+'0';
                if(nums[j]%p == 0)
                    count++;
                if(count<=k)
                    s.insert(str);
                else
                    break;
            }
        }
        return s.size();  
    }
};
