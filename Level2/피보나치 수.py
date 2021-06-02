#피보나치 수
n=5
def solution(n):
    fibo=[]
    #피보나치 수열 반복문
    for i in range(0,n):
        if i<2: #3보다 작을 경우 리스트에 담으니 2로 표현
            fibo.append(1)
        else:
            fibo.append(fibo[i-1]+fibo[i-2]) #다음 리스트에 합으로 표현
    return fibo[n-1]%1234567 #문제 조건
print(solution(n))
