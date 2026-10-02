class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets -> push into stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // Closing brackets
            else {
                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                // Check matching pair
                if (c == ')' && st.top() != '(') {
                    return false;
                }

                if (c == '}' && st.top() != '{') {
                    return false;
                }

                if (c == ']' && st.top() != '[') {
                    return false;
                }

                // Remove matched opening bracket
                st.pop();
            }
        }

        // Stack should be empty if everything is matched
        return st.empty();
    }
};