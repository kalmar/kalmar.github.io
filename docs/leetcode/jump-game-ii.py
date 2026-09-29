class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        jc = [0] * n
        for i in range(n):
            for j in range(1, nums[i]+1):
                if i + j < n:
                    jc[i + j] = min(jc[i + j], jc[i] + 1) if jc[i + j] != 0 else jc[i] + 1
                else:
                    break
        return jc[-1]

print(Solution().jump([2,3,1,1,4]))