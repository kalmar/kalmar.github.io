class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) < 1:
            return ""
        
        rev_s = s[::-1]
        for i in range(len(s)):
            if s.startswith(rev_s[i:]):
                return rev_s[:i] + s
        
        return ""

s = "abcdef"
rev_s = s[::-1]
print(s)
print(s[::-1])
print(rev_s[2:])
print(rev_s[2:5])