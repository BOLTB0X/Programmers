#3진법 뒤집기
def solution(n):
    answer =''
    result=0
    while n>=1: #반복문으로 3진수 구하기
        r=n%3
        n//=3
        answer+=str(r)
    i=0 #3의 승을 위해
    for idx in range(len(answer)-1,-1,-1): #리스트 탐색을 오른쪽->왼쪽으로 하기위해
        result+=int(answer[idx])*(3**i)  #각자리수*3^i
        i+=1
    return result
print(solution(45))