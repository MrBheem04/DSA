class Solution {
public:
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        return -1;
    }

    string infixToPostfix(string &s) {
        stack<char> st;
        string result;

        for (char c : s) {

            if (isalnum(c)) {
                result += c;
            }

            else if (c == '(') {
                st.push(c);
            }

            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); // remove '('
            }

            else { // operator
                while (!st.empty() && st.top() != '(' &&
                       (prec(c) < prec(st.top()) ||
                        (prec(c) == prec(st.top()) && c == '^'))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }

    string infixToPrefix(string &s) {

        // Reverse the infix expression
        reverse(s.begin(), s.end());

        // Swap brackets
        for (char &c : s) {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        // Convert to postfix
        string postfix = infixToPostfix(s);

        // Reverse postfix to get prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }
};