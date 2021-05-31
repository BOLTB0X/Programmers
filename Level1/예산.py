#예산
def solution(d, budget):
    answer=0
    d.sort() # 오름 차순으로 리스트 정렬
    while budget < sum(d): # 리스트의 총합이 예산보다 크면 반복
        d.pop() #제일 큰값을 빼라
    return len(d)
    return answer
d=[1,3,2,5,4]
budget=9
print(solution(d,budget))