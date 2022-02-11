// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int result;
        while (k > 0) {
            result = pq.top();
            pq.pop();
            k -= 1;
        }
        return result;
    }
};