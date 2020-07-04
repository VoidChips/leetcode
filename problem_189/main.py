from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        length: int = len(nums)
        arr: List = nums[:length-k]
        arr2: List = nums[length-k:length]
        nums[:] = arr2 + arr
        print(nums)

x = Solution()
y = Solution()
x.rotate([1,2,3,4,5,6,7], 3)
y.rotate([3, -100, 3, 99], 2)