// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        string openb = "({[";
        string closedb = ")}]";
        int pos2;
        char close;
        bool closed = false;
        for (auto c : s) {
            for (int j = 0; j < openb.size(); j++) {
                if (openb[j] == c) {
                    s1.push(c);
                    closed = true;
                }
            }
            if (!closed) {
                for (int j = 0; j < closedb.size(); j++) {
                    if (closedb[j] == c) {
                        pos2 = j;
                    }
                }
                if (!s1.empty()) {
                    if (s1.top() == openb[pos2]) {
                        s1.pop();
                    }
                }
            }
            closed = false;
        }
        if (s1.empty()) {
            return true;
        } else {
            return false;
        }

    }
};
