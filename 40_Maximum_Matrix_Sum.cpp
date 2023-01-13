class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int sum = 0 , mn = INT_MAX ,  count=0;
        for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix.size();j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j]<0)
                    count++;
                mn = min(mn , abs(matrix[i][j])*1LL);
            }
        }
        if(count%2)
            return sum-2*mn;
        else
            return sum;
    }
};
