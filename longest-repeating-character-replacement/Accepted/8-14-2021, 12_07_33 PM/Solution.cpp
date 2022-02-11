// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int charstoreplace;
        int count = 1;
        int windowstart = 0, maxlength = 0;
        map<char, int> charfreq;
        for (int windowend = 0; windowend < s.size(); windowend++) {
            char rightchar = s[windowend];
            if (charfreq.find(rightchar) != charfreq.end()) {
                ++charfreq[rightchar];
            } else {
                charfreq[rightchar] = 1;
            }
            for (auto item : charfreq) {
                if (item.second > count) {
                    count = item.second;
                }

            }
            charstoreplace = (windowend - windowstart + 1) - count;

            if (charstoreplace > k) {
                char leftchar = s[windowstart];
                --charfreq[leftchar];
                ++windowstart;
                charstoreplace = (windowend - windowstart + 1) - count;
            }

            maxlength = max(maxlength, windowend - windowstart + 1);
        }
        return maxlength;

        return 0;
    }
};