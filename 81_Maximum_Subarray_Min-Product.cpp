class Solution {
    int N=1e9+7;
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        stack<int> st;
        vector<int> arr1(n, -1);
        vector<int> arr2(n, n);
        for(int i = 0; i < n; i++){
            while(st.empty() == false && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                arr1[i] = -1;
            else
                arr1[i] = st.top();
            st.push(i);
        }
        while(st.empty() == false)
            st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(st.empty() == false && nums[st.top()] >= nums[i])
                st.pop();
            if(st.empty())
                arr2[i] = n;
            else
                arr2[i] = st.top();
            st.push(i);
        }
        long long mx = 0;
        for(int i = 0; i < n; i++){
            long long sum = 0;
            sum += prefix[arr2[i] - 1];
            if(arr1[i] >= 0)
                sum -= prefix[arr1[i]];
            sum *= nums[i];
            mx = max(mx, sum);
        }
        return mx % N;
    }
};
