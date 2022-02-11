// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        /*
        reverse a string recursively 
        Two pointer recursive technique with i and j 
        base case:
            when s and i reach the middle stop swapping and return
            h e l l o
            0 1 2 3 4 
                R L
        */
        int size = s.size();
        int mid = (s.size() - 1) / 2;
        int i = 0;
        int j = size - 1;
        reversestring(i, j, mid, s);
    }
    
    void reversestring(int i, int j, int mid, vector<char>&s) {
        int temp;
        if ((i == mid and j == mid) or i > j) {
            return;
        }
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        reversestring(i + 1, j - 1, mid, s);
        
    }
};