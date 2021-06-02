#N개의 최소공배수
arr=[2,6,8,14]
#최대공약수 정의
def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)
#3개 이상의 최소공배수
def solution(arr):
    def lcm(a,b):
        return a*b//gcd(a,b)
    while True:
        arr.append(lcm(arr.pop(),arr.pop())) #먼저 두개의 최소 공배수를 구함
        #그 최소 공배수를 다시 리스트에 넣어 리스트의 길이가 1이 될때 까지 반복
        if len(arr)==1:
            return arr[0]
print(solution(arr))

#https://programmers.co.kr/learn/courses/30/lessons/12953