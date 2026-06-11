// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>st;
        int n = pre_exp.size();
        
        for(int i=n-1;i>=0;i--){
            char c = pre_exp[i];
            
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                st.push("(" + op1 + c + op2 + ")");
            }
        }
        return st.top();
    }
};