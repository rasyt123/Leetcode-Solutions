// https://leetcode.com/problems/find-median-from-data-stream

from heapq import *


class MedianFinder:

    def __init__(self):
        self.max_heap = []  # containing first half of numbers
        self.min_heap = []  # containing second half of numbers

    def addNum(self, num: int) -> None:
        #if the number we want to insert is less than the biggest from lower half
        #insert the element into the max heap 
        if not self.max_heap or -self.max_heap[0] >= num:
            heappush(self.max_heap, -num)
        else:
            #otherwise insert into the min heap
            heappush(self.min_heap, num)

            
        #for balancing 
        # either both heaps will have equal number of elements or max-heap will have one more element
        if len(self.max_heap) > len(self.min_heap) + 1:
            #if there's more than a 1 diff between min heap and max_heap,
            #balance by popping the 
            heappush(self.min_heap, -heappop(self.max_heap))
        elif len(self.max_heap) < len(self.min_heap):
            heappush(self.max_heap, -heappop(self.min_heap))

    def findMedian(self) -> float:
        # we have even number of elements, take the average of middle two elements
        if len(self.max_heap) == len(self.min_heap):
            return -self.max_heap[0] / 2.0 + self.min_heap[0] / 2.0
        # we have odd number of elements, the first element in max-heap is the median element
        return -float(self.max_heap[0])

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()