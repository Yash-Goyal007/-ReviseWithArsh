class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0, j=0;
        vector<int>v(3, 0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            while(v[0] && v[1] && v[2]){
                count+=s.size()-i;
                v[s[j]-'a']--;
                j++;
            }
        }
        return count;
    }
};
