class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                b+=a;
                st.push(b);
            }
            else if(tokens[i]=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                b-=a;
                st.push(b);
            }
            else if(tokens[i]=="*"){
                int a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                b*=a;
                st.push(b);
            }
            else if(tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                b/=a;
                st.push(b);
            }
            else{
                int temp=stoi(tokens[i]);
                st.push(temp);
            }
        }
        int c=st.top();
        st.pop();
        return c;
    }
};
