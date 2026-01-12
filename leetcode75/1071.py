class Solution:
    def gcdOfStrings(self, a: str, b: str) -> str:
        from math import gcd
        return a[:gcd(len(a), len(b))] if a + b == b + a else ""
