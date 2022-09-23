class Solution:
    def concatenatedBinary(self, n: int) -> int:
        return int(''.join([bin(i)[2:] for i in range(1,n+1)]),2)%1000000007
        