#include <string>

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2*k) {
            int left = i;
            int right = min(i + k - 1, n - 1); // Ensure we don't go beyond the end of the string
            
            // Reverse the group of k characters
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        
        return s;
    }
};
