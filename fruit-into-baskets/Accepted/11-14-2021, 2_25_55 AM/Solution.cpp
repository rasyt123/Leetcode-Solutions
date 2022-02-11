// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
    
        The starting tree will be at fruits[0]
        we keep growing the sliding the window to the right, picking the trees until our two
        baskets are full. When we've exceeded the number of types for the fruit in the basket, 
        we stop, and then shrink sliding window to the left by 1. 
        
        we compute the maximum fruit picked at every iteration 
        
        */
        
        map<int, int> baskets;
        int l = 0;
        int maxfruit = 0;
        for (int start = 0; start < fruits.size(); start++) {
            ++baskets[fruits[start]];
            while (baskets.size() > 2) {
                --baskets[fruits[l]];
                if (baskets[fruits[l]] == 0) {
                    baskets.erase(fruits[l]);
                }
                l += 1;
            }
            maxfruit = max(maxfruit, start - l + 1);
        }
        return maxfruit;
        //[3, 3, 3, 1, 2]
        // 0  1  2  3  4 
        
        
        //3 3 1 2 
    }
};