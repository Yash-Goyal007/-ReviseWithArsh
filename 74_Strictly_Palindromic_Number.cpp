class Solution {
public:
    bool palindrome(string &s){
        int temp=0;
        int n=s.size()-1;
        while(temp<n){
            if(s[temp]==s[n]){
                temp++;
                n--;
            }
            else
                return false;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            int temp=n;
            string s;
            while(temp>0){
                s.push_back(temp%i);
                temp/=i;
            }
            if(!palindrome(s))
                return false;
        }
        return true;
    }
};
