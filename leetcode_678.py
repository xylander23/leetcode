class Solution:
    def checkValidString(self, s: str) -> bool:
        if len(s) == 0:
            return True
        if s[0] == ')':
            return False
        else:
            stack = []
            spend = 0
            for index, cha in enumerate(s):
                if cha == "(":
                    stack.append(cha)
                elif cha == "*":
                    if not stack:
                        spend += 1
                    else:
                        stack.pop(-1)
                        spend += 2
                else:
                    if stack:
                        stack.pop(-1)
                    elif spend > 0:
                        spend -= 1
                    else:
                        return False
            return not stack