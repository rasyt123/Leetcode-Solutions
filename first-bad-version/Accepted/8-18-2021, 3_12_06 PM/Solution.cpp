// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
        Binary Search Problem 
        
        I have to call isBadVersion inside of here
        all the versions after a bad version are also bad 
        
        imagine 5 versions [1, 2, 3, 4, 5]
        
        [1, 2]
         0  1 
         L  R
         m
         
         [1, 2, 3]
         
         [1]
          R
          L
          M
         
        Set bad to be the middle every time 
    
        Divide the number of versions in half and store the middle
        
        if the middle isn't bad,
            then search the right half to see if they are bad
        otherwise if the middle is bad:
            search the left half to see if they are bad
        */
    
        int l = 1, r = n;
        int bad;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                bad = mid;
            }
            if (!isBadVersion(mid)) {
                l = mid + 1;
            } else if (isBadVersion(mid)) {
                r = mid - 1;
            }
        }
        return bad;
    }
};