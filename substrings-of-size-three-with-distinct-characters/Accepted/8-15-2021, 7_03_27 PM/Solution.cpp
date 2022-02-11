// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
   int countGoodSubstrings(string s) {

       /*

       Sliding Window Approach:
       Return number of substrings of size 3 that
       have no unique characters
       slide to the right 3 every iteration

       keep expanding the window until we have a size of 3
       if the characters in the hashmap are all distinct, then
       we calculate the length
       */
       map<char, int> charfreq;
       int goodstringcount = 0;
       int windowstart = 0;
       bool good = true;
       for (int windowend = 0; windowend < s.size(); windowend++) {
           char rightchar = s[windowend];
           if (charfreq.find(rightchar) != charfreq.end()) {
               ++charfreq[rightchar];
           } else {
               charfreq[rightchar] = 1;
           }
           if (windowend - windowstart + 1 == 3) {
               for (auto item : charfreq) {
                   if (item.second > 1) {
                       good = false;
                       break;
                   }
               }
               if (good) {
                   ++goodstringcount;
               }
               char leftchar = s[windowstart];
               --charfreq[leftchar];
               if (charfreq[leftchar] == 0) {
                   charfreq.erase(leftchar);
               }
               windowstart++;
           }

           good = true;
       }
       return goodstringcount;

   }
};
