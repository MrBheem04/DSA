class Solution {
  public:
    string postToPre(string s) {
        // code here
        stack<string>st;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            char c = s[i];
            
            if(isalnum(c)){
                st.push(string(1,c));
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                
                st.push(string(1,c) + op2 + op1);
            }
        }
        return st.top();
    }
};