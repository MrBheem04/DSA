class Solution {
  public:
    string preToPost(string &s) {
        // code here
        stack<string>st;
        int n = s.size();
        
        for(int i=n-1;i>=0;i--){
            char c = s[i];
            
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                st.push(op1 +op2 + c );
            }
        }
        return st.top();
    }
};