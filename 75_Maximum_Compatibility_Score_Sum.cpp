class Solution {
public:
    
    int calculate(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& arr){
        int n = students.size();
        int sum = 0;
        for(int i = 0; i < n; i++){   
            for(int j = 0; j < students[i].size(); j++){
                if(students[i][j] == mentors[arr[i]][j])
                    sum++;
            }
        }
        return sum;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors){
        int n = students.size();
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = i;
        int mx = INT_MIN;
        do{
            int ans = calculate(students, mentors, arr);    
            mx = max(mx, ans);
        }
        while(next_permutation(arr.begin(), arr.end()));
        return mx;
    }
};
