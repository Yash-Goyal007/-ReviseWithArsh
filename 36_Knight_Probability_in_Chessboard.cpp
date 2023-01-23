class Solution {
public:
    double knightProbability(int n, int k, int row, int column){
        vector<int> x = {-2,-1,1,2,2,1,-1,-2};
        vector<int> y = {1,2,2,1,-1,-2,-2,-1};
        vector<vector<double>> temp(n,vector<double>(n,0.0));
        temp[row][column] = 1.0;
        for(int m =0;m<k;m++){
            vector<vector<double>> temp2(n,vector<double>(n,0.0));
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(temp[i][j] != 0.0){
                        for(int z = 0;z<8;z++){
                            int x1 = i+x[z];
                            int y1 = j+y[z];
                            if(x1 >= 0 && x1 <n && y1 >= 0 && y1 <n)
                                temp2[x1][y1] += temp[i][j]/8.0;
                        } 
                    }
                }
            }
            temp = temp2;       
        }
        double ans = 0.0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                ans += temp[i][j];
        }       
        return ans;
    }
};
