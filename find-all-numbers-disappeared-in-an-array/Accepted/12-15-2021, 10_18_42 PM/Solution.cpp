// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        use an unordered_map that maps 1 - n with the indexes 
        with each value in the vector being 
        1 2 3 4 5 6 .. n 
        mark all the entries to be false 
        
        iterate through nums and edit all entries from nums in that second array to be true 
        
        iterate through the new array and for each entry that is false 
        push it to a new array and be done 
        O(n) time but not O(n) space
        */
        
        vector<bool> vec(nums.size() + 1, false);
        vector<int> resultvec;
        for (int i = 0; i < nums.size(); i++) {
            vec[nums[i]] = true;        
        }
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == false) {
                resultvec.push_back(i);
            }
        }
        return resultvec;
        
    }
};