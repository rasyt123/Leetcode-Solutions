// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        //loop through both arrays with different indexes
        //
        // should keep repeating until we've exhausted all the elements in nums2 or imd
        //      if the element at nums2 at index j is less than or equal to nums1's index at i
        //              shift nums1 to the right, insert element at index i
        //              we want to increment j now;
        //
        //      if the element at nums2 at index j is more than index i,
        //             increment i but dont insert any element just yet
        //
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        int j = 0;
        int i = 0;
        int temp = nums1[m - 1];

        while (j < nums2.size()) {
            if (nums2[j] <= nums1[i] and temp > nums2[n - 1]) {
                for (int a = m - 1; a >= i; a--) {
                    nums1[a + 1] = nums1[a];
                }
                nums1[i] = nums2[j];
                ++i;
                ++j;
                ++m;
            } else if (nums2[j] <= nums1[i]) {
                for (int a = m - 1; a >= i; a--) {
                    nums1[a + 1] = nums1[a];
                }
                nums1[i] = nums2[j];
                ++i;
                ++j;
                ++m;
            } else if (nums2[j] >= nums1[i] and nums1.size() == nums2.size()) {
                nums1[i++] = nums2[j++];
            }else if (temp > nums2[n - 1] and nums2[j] >= nums1[i]) {
                ++i;
            } else if (nums2[j] >= nums1[i] and nums1[i] == 0 and i >= m  and i < m + n) {
                nums1[i++] = nums2[j++];
            } else {
                ++i;
            }

        }
        return;

        //temp > nums2[n - 1] and nums2[j] >= nums1[i] and nums1[i] == 0 and i >= m - nums2.size() and i < m + n

    }
};


   