#문자열을 정수로 바꾸기
def solution(s):
    answer = 0
    if s[0]=='-':
        answer+=int(s[1::])*-1
    else:
        answer+=int(s[1::])
    return answer
s='-1234'
print(solution(s))