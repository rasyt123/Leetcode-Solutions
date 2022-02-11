// https://leetcode.com/problems/3sum

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums) - 2):
            #This is len(nums) - 2 because you can't find anymore triplets when i is len(nums) - 2 
            #or greater
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            #we dont want to recompute all the same triplets again and we want to save
            #computation time
            l, r = i + 1, len(nums) - 1
            #we use two sum algorithm here but with the element at nums[i] we run two sum on every single 
            #number in the array 
            while l < r:
                #when l crosses r we've checked all of the items in between l and r that could be possible
                #solutions, so we should just halt the loop
                s = nums[i] + nums[l] + nums[r];
                if s < 0:
                    #the sum is too small so we should try shifting the left pointer to the right and see
                    #try computing the sum of the next biggest number
                    l += 1
                elif s > 0:
                    #sum is too big so we should try using the next smallest number and see if it matches up 
                    #with the target
                    r -= 1
                else:
                    #the sum is the target so we can add all the numbers that make up the target which are the elements
                    #at the pointers plus the item ur currently checking
                    res.append((nums[i], nums[l], nums[r]))
                    #once we find a match, there could be other triplets hiding so we need 
                    #to skip through all of the duplicates so we don't add extra triplets
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    #with duplicates we increment the pointers up until the last duplicate but the pointers are still on duplicates
                    #so we need to increment them one last time 
                    l += 1; r-= 1;
        return res