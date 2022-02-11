// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        We use two pointers 
        one l pointer and one r pointer
        
        l and r start at the front of the list 
        
  product = 0      
  while l or r are less than the list size 
        if the product is greater than k or r is greater than the length of nums ;
            increment l by 1
            set r = l
            reset the product 
            product = 0; 
        
        
        if the size of l - r is zero and the current item is less than k
            we add one to the counter 
        otherwise 
            keep multiplying whatever is at the l pointer by what is at the right pointer
            and set that to be the product 
            
        increment r by 1         
        */
        
    }
};