class Solution:

    def encode(self, strs: List[str]) -> str:

        res = ""

        for s in strs:
            res+=str(len(s))+'#'+s;

        return res

    def decode(self, s: str) -> List[str]:

        i = 0;
        ans = []
        while i<len(s):
            j = i

            while s[j]!='#':
                j+=1
            
            length = int(s[i:j]);
            word = s[j+1: j+length+1]
            ans.append(word)

            i = j+length+1

        return ans
