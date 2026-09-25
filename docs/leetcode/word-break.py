class Solution:
    dpw = []

    def wordBreak(self, s: str, wordDict: list[str]) -> list[str]:
        word_set = set(wordDict)
        dp = [False] * (len(s) + 1)
        dpw = [[] for _ in range(len(s) + 1)]
        dp[0] = True
        
        for i in range(1, len(s) + 1):
            for j in range(i):
                w = s[j:i]
                if dp[j] and w in word_set:
                    dp[i] = True
                    dpw[i].append((w, j))
        
        self.dpw = dpw

        return self.result( len(s) )

    def result(self, i: int) -> list[str]:
        if i == 0:
            return [""]

        res = []
        for s in self.dpw[i]:
            for r in self.result(s[1]):
                res.append((r + " " + s[0]).strip())
        
        return res

        
print(Solution().wordBreak("catsanddog", ["cat","cats","and","sand","dog"]))