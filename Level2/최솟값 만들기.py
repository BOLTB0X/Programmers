#최솟값 만들기
a=[1,4,2]
b=[5,4,4]
def solution(a,b):
    answer = 0
    a.sort()
    b.sort(reverse=True)
    for i in range(len(a)):
            answer+=a[i]*b[i]
    return answer
print(solution(a,b))
#https://programmers.co.kr/learn/courses/30/lessons/12941