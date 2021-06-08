s='(()('
def solution(s):
    answer = True
    stack=[] #스택 이용
    for i in range(len(s)):
        if len(stack)==0:
            if s[i]=='(':
                stack.append(s[i])
            else:
                stack.append(s[i])
                break
        else:
            if s[i]==')' and stack[-1]=='(':
                stack.pop()
            else:
                stack.append(s[i])
    if len(stack)!=0:
        answer=False
    return answer
print(solution(s))