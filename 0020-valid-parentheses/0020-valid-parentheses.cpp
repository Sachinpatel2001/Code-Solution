#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stk.empty()) {
                    return false;  // No matching opening character
                }
                char top = stk.top();
                stk.pop();
                if ((c == ')' && top != '(') || 
                    (c == ']' && top != '[') || 
                    (c == '}' && top != '{')) {
                    return false;  // Mismatched opening and closing characters
                }
            }
        }

        return stk.empty();  // Stack should be empty for a valid string
    }
};

// int main() {
//     Solution solution;
//     string s = "{[()]}";
//     cout << (solution.isValid(s) ? "Valid" : "Invalid") << endl;
//     return 0;
// }
