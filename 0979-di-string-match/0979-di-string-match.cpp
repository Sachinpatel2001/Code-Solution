class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int low = 0; // The lower bound for the numbers
        int high = n; // The upper bound for the numbers
        
        vector<int> result;
        
        for (char c : s) {
            if (c == 'I') {
                result.push_back(low);
                low++;
            } else if (c == 'D') {
                result.push_back(high);
                high--;
            }
        }
        
        // Add the remaining number (either low or high)
        result.push_back(low);
        
        return result;
    }
};
