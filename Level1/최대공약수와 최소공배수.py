#최대공약수와 최소공배수
def solution(n, m):
    def gcd(n,m):
        if n%m==0:
            return m
        else:
            return gcd(m,n%m)
    answer = []
    answer.append(gcd(n,m)) ##최대공약수
    answer.append(n*m//gcd(n,m)) ##최소공배수
    return answer
n,m=map(int,input().split())
print(solution(n,m))