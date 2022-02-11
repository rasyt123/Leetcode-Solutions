// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        
        */
        //vector of integers with the indexes
        //
        //loop through the array
        //add all of the keys with the indexes to the hashmap 
        //x + y = target
        // loop again:
        //    set z to be the target - a[i]
        
        // look the item up in the hashtable and add it to a[i]
        //    if the target matches
        //       pushback the value from the hasmap into the vector 
        // 
        // 
        //a[0] = 2; target - a[0]
        vector<int> twosumints;
        map<int, int> hashmap;
        int z;
        for (int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            z = target - nums[i];
            if (hashmap.count(z) > 0 and hashmap[z] != i) {
                twosumints.push_back(i);
                twosumints.push_back(hashmap[z]);
                break;
            }
        }
        
        return twosumints;
    
        
    }
};