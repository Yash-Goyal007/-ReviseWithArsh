class Solution {
public:
    vector<int> v;
    int n;
    Solution(vector<int>& nums) {
        v = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> arr = v;
        int temp = n;
        for(int i=n-1;i>-1;i--){
            int index = rand()%temp--;
            swap(arr[index],arr[i]);
        }
        return arr;
    }
};  
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
