class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // If it's an opening bracket, push it to the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            // If it's a closing bracket, check for matching top element
            else {
                if (st.empty()) return false; // Closing bracket with no opening pair
                
                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop(); // Valid match, remove from stack
                } else {
                    return false; // Mismatched brackets
                }
            }
        }
        
        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};