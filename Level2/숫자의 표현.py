#숫자의 표현
n=15
def solution(n):
    answer = 0
    for i in range(1,n+1):
        tot=0
        for j in range(n+1):
            tot+=(i+j)
            if tot==n:
                answer+=1
                break
            if tot>n:
                break
    return answer
print(solution(n))
#https://programmers.co.kr/learn/courses/30/lessons/12924