// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
       map<char, int> s1chars;
       map<char, int> s2chars;
       
       for (char item : s) {
           if (s1chars.find(item) != s1chars.end()) {
               ++s1chars[item];
           } else {
             s1chars[item] = 1;     
           }
          
       }
        
       for (char item : t) {
            if (s1chars.find(item) != s1chars.end()) {
               ++s2chars[item];
           } else {
             s2chars[item] = 1;     
           }
           
       }
        
        if (s1chars == s2chars) {
            return true;
        } else {
            return false;
        }
    }
};