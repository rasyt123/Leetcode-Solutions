// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        We can use a fixed sliding window approach. In each portion of the window, we can 
        create a copy of the window string and sort it and compare it to see if s1 is the same 
        as the copied string.
        
        */
    	sort(s1.begin(), s1.end());
    	int windowstart = 0;
    	int k = s1.size();
    	string perm;
    	for (int windowend = 0; windowend < s2.size(); windowend++) {
    		if (windowend - windowstart + 1 == k) {
    			//Create a copy substring here
    			perm = s2.substr(windowstart, k);
                sort(perm.begin(), perm.end());
    			if (perm == s1) {
    				return true;
    			}
    			++windowstart;
    		}
    	}
    	return false;
    }
};