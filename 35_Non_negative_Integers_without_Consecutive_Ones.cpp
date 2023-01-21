class Solution {
public:
    int findIntegers(int n) {
        int fibo[32];
        fibo[0] = 1;
        fibo[1] = 2;
        for (int i = 2; i < 32; ++i)
            fibo[i] = fibo[i-1]+fibo[i-2];
        int ans = 0, temp = 30, prev = 0;
        while (temp >= 0) {
            if (n &(1<<temp)) {
                ans += fibo[temp];
                if (prev) return ans;
                prev = 1;
            }
            else
                prev = 0;
            --temp;
        }
        return ans+1;
    }
};
