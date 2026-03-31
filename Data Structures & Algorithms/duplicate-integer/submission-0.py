class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        different = []
        for num in nums:
            if num in different:
                return True
            else:
                different.append(num)
        return False
    
