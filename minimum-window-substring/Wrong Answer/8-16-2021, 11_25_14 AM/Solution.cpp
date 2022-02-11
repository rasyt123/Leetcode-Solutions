// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int windowstart = 0;
        int windowend = 0;
        string otherstring;
        string comparison;
        int size = s.size();
        bool status = false;
        map<char, int> schars;
        map<char, int> tchars;
        if (s == t) {
            return s;
        }
        if (t.size() > s.size()) {
            comparison = "";
            return comparison;
        }
        for (int i = 0; i < t.size(); i++) {
            if (tchars.find(t[i]) != tchars.end()) {
                ++tchars[t[i]];
            } else {
                tchars[t[i]] = 1;
            }
        }
        while (windowend < s.size()) {
            char rightchar = s[windowend];
            if (schars.find(rightchar) != schars.end()) {
                ++schars[s[windowend]];
            } else {
                schars[s[windowend]] = 1;
            }
            while (includesstring(schars, tchars)) {
                char leftchar = s[windowstart];
                --schars[leftchar];
                if (schars[leftchar] == 0) {
                    schars.erase(leftchar);
                }
                otherstring = s.substr(windowstart, windowend - windowstart + 1);
                if (otherstring.size() < size) {
                    comparison = otherstring;
                    size = otherstring.size();
                }
                ++windowstart;
            }
            ++windowend;
        }

        return comparison;


    }


    bool includesstring(map<char, int>& schars, map<char, int>& tchars) {

        for (auto item : tchars) {
            if (schars.find(item.first) == schars.end()) {
                return false;
            }
        }
        return true;
    }

};


