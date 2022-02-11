// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {


        /*

        s = "ahgd"
             L  R

             "afzg"
               LR


              "abc"
                L
                R
        have and L and R for both s and t
        when the value at both left pointers are equal, shift both s's and l's left pointer to the
        right
        if the left pointer of t is not equal to the L pointer of S, shift t's pointer to the right but
        not s's pointer


        when the value at both right pointrs are equal, shift both s's and l's right pointer to the
        left. if the right pointers of t is not equal to the right pointer of S, shift t's pointer to left


        if t's left and right pointers cross
        we should return false
        t = "ahbgdc"
               L
               R "doesnt exist "
               Should return false inside of the subesqeunce


        return true

        */
        int sl, sr;
        int tl, tr;

        sl = 0;
        sr = s.size() - 1;

        tl = 0;
        tr = t.size() - 1;

        while (sl <= sr) {
            if (tl > tr) {
                return false;
            }

            if (s[sl] == t[tl]) {
                ++sl;
                ++tl;
            } else if (s[sl] != t[tl]) {
                ++tl;
            }

            if (s[sr] == t[tr]) {
                --sr;
                --tr;
            } else if (s[sr] != t[tr]) {
                --tr;
            }

        }

        return true;





    }
};