// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<char> s1;
        stack<int> s2;
        string temporary;
        string decoded;
        string what;
        int numtimes;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '[' and s[i] != ']' and !isalpha(s[i])) {
                what += s[i];
            } else if (s[i] == '[') {
                s1.push(s[i]);
                s2.push(stoi(what));
                what.clear();
            } else if (!s1.empty() and s1.top() == '[' and s[i] == ']') {
                s1.pop();
                numtimes = s2.top();
                s2.pop();
                if (s1.empty() and temporary.empty()) {
                    temporary += decoded;
                    decoded.clear();
                }
                for (int i = 0; i < numtimes; i++) {
                    decoded += temporary;
                }
                temporary.clear();
            } else {
                if (i + 1 < s.size() and !isalpha(s[i + 1]) and s[i + 1] != '[' and s[i + 1] != ']') {
                    temporary += s[i];
                    decoded += temporary;
                    temporary.clear();
                } else {
                    temporary += s[i];
                }
            }
        }
        if (!temporary.empty()) {
            decoded += temporary;
        }
        return decoded;
    }
};
