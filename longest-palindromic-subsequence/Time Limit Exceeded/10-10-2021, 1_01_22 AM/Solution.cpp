// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
        two pointers l pointer on left and r pointer on right 
        
        Sub problems:
        When breaking down the palindrome and removing characters to see
        if the palindrome is nested in another portion of the string, the same 
        check might occur so we can reuse the value of the longest palindromic substring 
        
        how will I get the string itself 
      
        
        I need to compare the pointers at the front of the string and the back of the string 
        if the characters are equal, that portion of the string is part of the palidrome, so we
        can increment left pointer and decrement right pointer 
        
     
        bbbab
        
        
        bba
          bb
          ba
          
        
        palindromicsub(string s, i, j) 
        if the length of palindromic sub is gr
        */
        int stringsize = s.size();
        vector<vector<int>> dp(stringsize, vector<int>(stringsize, 0));
        int result;
        result = palindromicsub(s, 0, s.size() - 1, dp);
        if (result == 0) {
            return 1;
        }
        return result;
    }
    
    
    
    //Brute force solution
    
    int palindromicsub(string s, int i, int j, vector<vector<int>> dp) {
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        if (i > j) {
            return dp[i][j];
        } else if (i == j) {
            dp[i][j] = 1;
        } else if (s[i] == s[j]) {
          dp[i][j] = 2 + palindromicsub(s, i + 1, j - 1, dp);
        } else {
          dp[i][j] = max(palindromicsub(s, i + 1, j, dp), palindromicsub(s, i, j - 1, dp));
        }
        return dp[i][j];
        
    }
};