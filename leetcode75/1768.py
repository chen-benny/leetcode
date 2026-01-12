class Solution:
    def mergeAlternately(self, a: str, b: str) -> str:
        return ''.join(x + y for x, y in zip(a, b)) + a[len(b):] + b[len(a):]
