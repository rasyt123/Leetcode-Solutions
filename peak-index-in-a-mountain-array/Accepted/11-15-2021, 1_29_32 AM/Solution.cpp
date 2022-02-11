// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        /*
        Straightforward o(n) solution 
        we go through the vector arr and 
        we check if the the item at the index previous 
        is less than the current value and of the item + 1 
        ahead of us is less than the current value
        
        [24,69,100,99,79,78,67,36,26,19]
         0  1   2  3  4  5 6  7    8 9 
         
         o(log n) solution 
         
      while (l < r)  
      
         if the item at the middle is the one we want:
            return it 
        otherwise if item previous is greater than the current  or there is no previous
             we look at left sorted portion
             r = mid
        otherwise
             we look at the right sorted portion 
        
        [24, 69, 100, 99]
         0   1   2    3 
         
         [100, 99]
           2   3 
           l   r
           
           [0, 2, 1, 0]
            0  1  2  3}
  }
 */
        if (arr.size() == 0) {
            return 0;
        }
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
                return i;
            }
        }
        return 0;
    }
};