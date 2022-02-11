// https://leetcode.com/problems/word-break

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        
        dp = [False for i in range(len(s) + 1)] #(1)
        dp[0] = True
        
        for i in range(len(s) + 1): #(2)
            for j in range(i):
                if dp[j] and s[j:i] in wordDict: #(3)
                    dp[i] = True
                    break #(4)
        
        return dp[len(s)] #(5)
        