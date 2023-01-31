class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double temp1 = ((double)rand()/RAND_MAX * (2*r)) + (x-r);
        double temp2 = ((double)rand()/RAND_MAX * (2*r)) + (y-r);
        while(solve(temp1,temp2,x,y)>=r*r){
            temp1 = ((double)rand()/RAND_MAX * (2*r)) + (x-r);
            temp2 = ((double)rand()/RAND_MAX * (2*r)) + (y-r);
        }
        return {temp1,temp2};
    }
    
    double solve(double temp1,double temp2,double x,double y)
    {
        return (x-temp1)*(x-temp1) + (y-temp2)*(y-temp2);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
