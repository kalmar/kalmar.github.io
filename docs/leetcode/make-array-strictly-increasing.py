from bisect import bisect
import sys


class Solution:
    def makeArrayIncreasing(self, arr1: list[int], arr2: list[int]) -> int:
        dp = {}
        arr2.sort()
        
        def dfs(i, prev):
            if i == len(arr1):
                return 0
            if (i, prev) in dp:
                return dp[(i, prev)]

            cost = float('inf')
            
            # If arr1[i] is already greater than prev, we can leave it be.
            if arr1[i] > prev:
                cost = dfs(i + 1, arr1[i])
            
            # Find a replacement with the smallest value in arr2.
            idx = bisect.bisect_right(arr2, prev)
            
            # Replace arr1[i], with a cost of 1 operation.
            if idx < len(arr2):
                cost = min(cost, 1 + dfs(i + 1, arr2[idx]))

            dp[(i, prev)] = cost
            return cost

# print(Solution().makeArrayIncreasing([1,5,3,6,7], [1,3,2,4]))
print(Solution().makeArrayIncreasing([1,5,3,6,7], [4,3,1]))