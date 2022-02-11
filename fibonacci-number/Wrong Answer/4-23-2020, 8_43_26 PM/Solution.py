// https://leetcode.com/problems/fibonacci-number

class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return (N)
        return (N - 1) + (N - 2)