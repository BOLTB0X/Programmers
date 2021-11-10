#덱사용을 위한
from collections import deque

def solution(priorities, location):
    answer = 0
    
    #덱 선언
    #우선순위값과 인덱스를 넣어줌
    dq = deque([(v,i) for i,v in enumerate(priorities)])
    
    while dq:
        cur = dq.popleft()
        
        #덱이 비어있지 않고
        #현재 뽑은 우선순위 값이 현재 뽑은 것보다 크다면
        if dq and max(dq)[0] > cur[0]:
            dq.append(cur)
        else:
            answer += 1
            if cur[1] == location:
                break
            
    #반환
    return answer
