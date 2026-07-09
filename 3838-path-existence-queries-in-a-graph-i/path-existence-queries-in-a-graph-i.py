class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        """
        :type n: int
        :type nums: List[int]
        :type maxDiff: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        comp = [0] * n
        for i in range(1, n):
            comp[i] = comp[i-1] if nums[i] - nums[i-1] <= maxDiff else comp[i-1] + 1
        
        return [comp[u] == comp[v] for u, v in queries]
        