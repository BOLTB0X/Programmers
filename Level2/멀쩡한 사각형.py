#최대공약수
def gcd(a,b):
    if a%b == 0:
        return b
    else:
        return gcd(b,a%b)

def solution(w,h):
    answer = w*h -(w+h)
    answer += gcd(w,h)
    
    return answer