class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n=len(nums)
        xr=0
        for i in range(0,n):
            xr^=i
            xr^=nums[i]
        xr^=n
        return xr