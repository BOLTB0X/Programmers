from itertools import permutations
import math

#소수 판별
def is_prime(n):
    if n == 0 or n == 1:
        return False
    
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    
    return True

def solution(numbers):
    answer = 0
    per=[]
    
    #각 1부터 길이까지 순열을 만듬
    for i in range(1,len(numbers)+1):
        arr = list(permutations(numbers,i))
        #순열
        for j in range(len(arr)):
             per.append(int(''.join(map(str,arr[j]))))
    
    #중복제거
    per = list(set(per))
    
    #탐색
    for i in range(len(per)):
        if is_prime(per[i]):
            answer += 1
    
    #반환
    return answer
