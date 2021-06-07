s='baabaa'
def solution(s):
    answer=[]
    for i in range(len(s)):
        if not answer:
            answer.append(s[i])
        else:
            if s[i]==answer[-1]:
                answer.pop()
            else:
                answer.append(s[i])
    
    return 1 if len(answer)==0 else 0
print(solution(s))