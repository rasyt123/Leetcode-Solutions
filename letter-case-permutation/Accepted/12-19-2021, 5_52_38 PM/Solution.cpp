// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<bool> uppercase(s.size(), false);
        vector<string> permutedstrings;
        map<string, int> exists;
        permute(s, uppercase, permutedstrings, exists);
        return permutedstrings;
    }
    
    
    void permute(string s, vector<bool>& uppercase, vector<string>& permutedstrings, map<string, int>& exists) {
        if (exists[s]) {
            return;
        }
        exists[s] = 1;
        permutedstrings.push_back(s);
        for (int i = 0; i < s.size(); i++) {
            if (!uppercase[i] and isalpha(s[i]) and islower(s[i])) {
               char oldlowercase = s[i];
               s[i] = s[i] - 32;
               uppercase[i] = true;
               permute(s, uppercase, permutedstrings, exists);
               uppercase[i] = false;
               s[i] = oldlowercase;
            } else if (!uppercase[i] and isalpha(s[i]) and isupper(s[i])) {
               char olduppercase = s[i];
               s[i] = s[i] + 32;
               uppercase[i] = true;
               permute(s, uppercase, permutedstrings, exists);
               uppercase[i] = false;
               s[i] = olduppercase;
            }
        }
        return;
    }
    
    
    
    
    
};