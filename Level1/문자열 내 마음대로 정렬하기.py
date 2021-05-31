#문자열 내 마음대로 정렬하기
def solution(strings, n):
    answer=sorted(strings,key=lambda x:(x[n],x))
    return answer
string1=["sun", "bed", "car"]
string2=["abce", "abcd", "cdx"]
print(solution(string1,1))
print(solution(string2,2))
#https://programmers.co.kr/learn/courses/30/lessons/12915