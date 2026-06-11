// User function Template for C++

class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string>st;
        int n = exp.size();
        
        for(int i=0;i<n;i++){
            char c = exp[i];
            
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                
                st.push("(" + op1 + c + op2 + ")");
            }
        }
        return st.top();
    }
};