class Solution {
public:
    string tostring(long long n){
        if (n==0)   
            return "0";
        string ans;
        while (n>0){
            string s;
            s+= ((n%10)+'0');
            ans= s+ans;
            n/=10;
        }
        return ans;
    }
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator==0)
            return "0";
        string ans;
        if ((numerator<0 && denominator>0) || (numerator>0 && denominator<0))
            ans.push_back('-');
        numerator= abs(numerator); 
        denominator= abs(denominator);
        long long quotient= numerator/denominator;
        long long remainder= numerator%denominator;
        ans= ans+tostring(quotient);
        if (remainder==0)
            return ans;
        ans+='.';
        map<long long, int> mp;
        while (remainder != 0){
            if (mp.find(remainder)!= mp.end()){
                int temp= mp[remainder];
                ans.insert(temp,"(");
                ans+=')';
                break;
            }
            else {
                mp[remainder]= ans.length();
                remainder*= 10;
                quotient= remainder/denominator;
                remainder= remainder%denominator;
                ans+= tostring(quotient);
            }
        }
        return ans;
    }
};
