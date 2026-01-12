class Solution:
    def canPlaceFlowers(self, flowerbed: list[int], n: int) -> bool:
        sz = len(flowerbed)
        for i in range(sz):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == sz-1 or flowerbed[i+1] == 0):
                flowerbed[i] = 1
                n -= 1
        return n <= 0
