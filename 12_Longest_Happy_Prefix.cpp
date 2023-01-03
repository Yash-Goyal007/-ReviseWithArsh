class Solution {
public:
    string longestPrefix(string s) {
        if(s.size()==0)
            return "";
        vector<int> v(s.size(), 0);
        int i=0, j=1;
        while(j<s.size()){
            if(s[i]==s[j]){
                v[j]=i+1;
                i++; j++;
            }
            else{
                if(i ==0)
                    j++;
                else
                   i = v[i-1];  
            }
        }
        return s.substr(0,i);
    }
};
