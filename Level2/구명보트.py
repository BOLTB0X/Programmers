def solution(people, limit):
    answer = 0
    
    #정렬
    people.sort()
    
    #이분탐색처럼
    start = 0
    end = len(people) - 1
    
    #엇갈리기 전까지
    while (start <= end):
        #두명 데리고 가기
        if (people[start] + people[end] <= limit):
            start += 1
            end -= 1
        
        #한명만
        else:
            end -= 1
        
        #카운트
        answer +=1 
    
    #반환
    return answer
