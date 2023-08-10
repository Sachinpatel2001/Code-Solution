#include <string>

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false; // Strings of different lengths can't be rotated into each other
        }
        
        s += s; // Concatenate s with itself
        
        return s.find(goal) != string::npos; // Check if goal is a substring of s
    }
};
