// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    //check if anagram
    bool anagram (vector <int> mp, string st2, int n) {
        for (int i = 0; i < n; i++) if (--mp[st2[i]-'a'] < 0) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans, mp(26, 0);
        int window = p.size();
        for (int i = 0; i < window; i++) mp[p[i]-'a']++;
        for (int l = 0, r = l+window; r <= s.size(); l++, r++) if (anagram(mp, s.substr(l, r), window)) ans.push_back(l);
        return ans;
    }
}