# 제일 작은 수 제거
def solution(arr):
    answer = []
    min_value=min(arr) #리스트 안에 제일 작은 값
    arr.remove(min_value)
    if len(arr)!=0: #리스트 원소가 하나인 것을 대비
        for i in arr:
            answer.append(i)
    else:
        answer.append(-1)
    return answer
arr=list(map(int,input().split()))
print(solution(arr))