#약수의 합
def solution(n):
    answer = 0
    #약수 구하기
    for i in range(1,n+1):
        if n%i==0: #나눠지면
            answer+=i
    return answer
n=int(input())
print(solution(n))