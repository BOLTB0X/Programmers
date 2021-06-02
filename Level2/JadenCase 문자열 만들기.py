#jadenCase 문자열 만들기
s="3people unFollowed me"
def solution(s):
    s=s.split()
    answer=''
    for i in range(len(s)):
        s[i]=s[i].capitalize() #capitalize 이용
    answer=' '.join(s)
    return answer
print(solution(s))
