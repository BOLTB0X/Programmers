#하샤드 수
x=11
def solution(x):
    answer = False
    tot=0
    for n in str(x):
        tot+=int(n)
    if x%tot==0:
        answer=True
    return answer
print(solution(x))
