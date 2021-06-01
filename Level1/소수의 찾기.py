n=5
def is_prime_number(x): #소수 판별하는 함수
    if x<2: #2보다 작으면 소수가 아님
        return False
    for i in range(2,int(x**0.5)+1): #2부터 루트x까지 반복한다.
        if x%i==0: # x가 2부터 루트x까지 범위의 i에 나누어떨어지면 소수가 아님
            return False
    return True
def solution(n):
    answer=[]
    for i in range(2,n+1):
        if is_prime_number(i)==True: #소수면 answer리스트에 추가한다.
            answer.append(i)
    return len(answer)
print(solution(n))