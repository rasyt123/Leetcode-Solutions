// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        /*In a palindrome, the string is reversed but the string values are both the same on both ends of a string except
        for the middle character. We can place a left and right pointer at both ends of the string s, with l being at 0 and r being at
        r - 1;

        the moment s[l] and s[r] are not equal, we should return false;

        When both characters are equal, shift the left pointer to the right and the right pointer to the left
        once we get to the center, and  l and r are equivalent to each other, we have


        standard method is to reverse the string and then check if it is a palindrome, but this method takes more time
        than the two pointer solution.


        */


        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            s[l] = tolower(s[l]);
            s[r] = tolower(s[r]);
            while (!isalnum(s[l]) and l < s.size() - 1) {
                ++l;
            }
            while (!isalnum(s[r]) and r > 0) {
                --r;
            }


            if(s[l] == s[r]) {
                ++l;
                --r;
            } else {
                return false;
            }
        }
        return true;

    }
};