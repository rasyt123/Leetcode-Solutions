// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        We can use a fixed sliding window approach. In each portion of the window, we can
        create a copy of the window string and sort it and compare it to see if s1 is the same
        as the copied string.

        */
        map<char, int> freq;
        for (int i = 0; i < s1.size(); i++) {
            if (freq.count(s1[i]) == 0) {
                freq[s1[i]] = 1;
            } else {
                ++freq[s1[i]];
            }

        }
        int windowstart = 0;
        int k = s1.size();
        map<char, int> freq2;
        for (int windowend = 0; windowend < s2.size(); windowend++) {
            if (freq2.count(s2[windowend]) == 0) {
                freq2[s2[windowend]] = 1;
            } else {
                ++freq2[s2[windowend]];
            }
            if (windowend - windowstart + 1 == k) {
                if (freq == freq2) {
                    return true;
                }
                --freq2[s2[windowstart]];
                if (freq2[s2[windowstart]] == 0) {
                    freq2.erase(s2[windowstart]);
                }
                ++windowstart;
            }
        }
        return false;
    }
};

