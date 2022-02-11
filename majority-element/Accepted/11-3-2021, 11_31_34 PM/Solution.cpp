// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        int numtimes = nums.size() / 2
        insert the numbers into a hashtable with their frequency counts 
        loop through the items in the hashtable:
            if the count is greater than numtiems:
                return that element 
               
        */
        int numtimes = nums.size() / 2;
        map<int, int> freqmap;
        for (int i = 0; i < nums.size(); i++) {
            ++freqmap[nums[i]];
        }
        for (auto item : freqmap) {
            if (item.second > numtimes) {
                return item.first;
            }
        }
        return 0;
        
    }
};