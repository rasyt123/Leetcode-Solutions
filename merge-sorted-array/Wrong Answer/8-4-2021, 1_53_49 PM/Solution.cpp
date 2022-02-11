// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        if (n == 0) {
            return;
        }
        int j = 0;
        int i = 0;
        int temp;
        while (j < nums2.size()) {
            if (nums2[j] <= nums1[i]) {
                temp = nums1[m - 1];
                for (int a = nums1.size() - 2; a >= i; a--) {
                    nums1[a + 1] = nums1[a];
                }
                ++j;
            } else if (nums2[j] >= nums1[i] and nums1[i] == 0) {
                nums1[i] = nums2[j];
                ++i;
                ++j;
            }else {
                i++;
            }
        }
        return;



    }
};
