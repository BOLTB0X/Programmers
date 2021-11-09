def solution(progress,speeds):
    answer=[]
    #걸리는 일수
    days=[]
    
    #남은 일수로 총 몇 일걸리는지 
    for i in range(len(progress)):
        rest_progress = 100 - progress[i]
        if rest_progress % speeds[i]==0:
            days.append(rest_progress // speeds[i])
        else:
            days.append((rest_progress // speeds[i])+1)
            
    #비교
    cmp=days[0]
    day=1
    for i in range(1,len(days)):
        #배포가 불가능하면
        if cmp>=days[i]:
            day+=1
        
        #가능하면
        else:
            answer.append(day)
            cmp=days[i]
            day=1
            
    #마지막
    answer.append(day) 
    
    #반환
    return answer
