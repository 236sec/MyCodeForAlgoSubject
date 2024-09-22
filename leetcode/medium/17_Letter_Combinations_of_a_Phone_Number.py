class Solution(object):
    def combtext(self,ind,digits,textcomb,table,ans):
        if(ind == len(digits)):
            ans.append(textcomb)
            return
        for char in table[digits[ind]]:
            self.combtext(ind+1,digits,textcomb+char,table,ans)
        return

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if(digits == ""):
            return []
        mydict = {'2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],\
        '9':['w','x','y','z']}
        ans = []
        self.combtext(0,digits,'',mydict,ans)
        return ans