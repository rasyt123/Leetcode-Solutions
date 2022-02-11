// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        /*
        Use hashtable to store symbols with respective values
        we can go through the string s, if the character in front of it is larger
        than the current, we should use subtraction other wise keep adding the values
        Roman numerals are usually written largest to smallest from left to right

        */

        map<char, int> symbols;
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;
        int totalsum = 0;
        int subsum;
        for (int i = 0; i < s.size(); i++) {
            if (symbols[s[i + 1]] > symbols[s[i]]) {
                subsum = -(symbols[s[i]]);
                totalsum += subsum;
            } else {
                totalsum += symbols[s[i]];
            }
        }

        return totalsum;

    }
};