#문자열 내 p와 y의 개수
s="Pyy"
def solution(s):
    answer=False
    s=s.lower()
    p_cnt=s.count('p')
    y_cnt=s.count('y')
    if p_cnt==y_cnt:
        answer=True
    return answer
print(solution(s))