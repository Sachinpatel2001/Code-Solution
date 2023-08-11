#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildFinalString(s) == buildFinalString(t);
    }

private:
    string buildFinalString(const string& str) {
        string result;
        for (char c : str) {
            if (c == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
