// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), k = p.length();
        vector <int> v,freq(26,0),freq1(26,0);
        
        if(k>n || n==0 || k==0) // Edge cases 
            return {};
        
        for(char c:p)
            freq[c-'a']++;
        
        for(int i=0;i<k;++i)
            freq1[s[i]-'a']++;
        
        if(freq == freq1)
            v.push_back(0);
        
        for(int i=1;i<=n-k;++i)
        {
            freq1[s[i-1]-'a']--; // Removing previous character of window
            freq1[s[i+k-1]-'a']++; // Adding last character of window
            if(freq == freq1)
                v.push_back(i); // Index of start of window
        }
        return v;
    }
};