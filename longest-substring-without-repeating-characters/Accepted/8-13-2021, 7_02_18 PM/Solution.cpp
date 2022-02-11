// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowstart = 0, maxlength = 0;
        map<char, int> charfreq;
        for (int windowend = 0; windowend < s.size(); windowend++) {
            char rightchar = s[windowend];
            if (charfreq.find(rightchar) != charfreq.end()) {
                ++charfreq[rightchar];
            } else {
                charfreq[rightchar] = 1;
            }
            if (charfreq[rightchar] > 1) {
                while (charfreq[rightchar] > 1) {
                    char leftchar = s[windowstart];
                    --charfreq[leftchar];
                    if (charfreq[leftchar] == 0) {
                        charfreq.erase(leftchar);
                    }
                    ++windowstart;
                }
            }
            maxlength = max(maxlength, windowend - windowstart + 1);
        }
        return maxlength;
        
        
        /*
        
        
        s = "abcabcbb"
        
        For this problem, I will have the windowstart and end be at 0 because it is the first index
        
        
        The windowend will keep on growing, so I can add the windowend at s[windowend] into the hashmap because 
        we've included that specific character. 
        
        if you find the windoend in the hashtable count is greater than 1:
        
            while the count of the windowend is greater than 1:
                we take the windowstart char 
            
                decrease the frequency of that char  
                 if the frequency is zero:
                    remove the item from the hashtable
                windowstart++ 
        calculate the length of the window string
        
        
        
        I need to calculate the max length of the string constantly 
            
            
        
        */
       
        
        
        
    }
};