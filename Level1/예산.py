def solution(d, budget):
    answer = 0
    
    #오름차순 정렬
    d.sort()
    
    #예산이 크다면
    while budget < sum(d):
        #가장 큰 값 제거
        d.pop()
    
    #정답
    answer = len(d)
    
    #반환
    return answer
