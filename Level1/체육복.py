def solution(n,lost,reserve):
    #중복제거
    s_lost=list(set(lost)-set(reserve)) 
    s_reserve=list(set(reserve)-set(lost))
    
    for i in s_reserve:
        #분실 학생 제거
        if (i-1) in s_lost:
            s_lost.remove(i-1) 
        
        #분실 학생 제거
        elif (i+1) in s_lost:
            s_lost.remove(i+1) 
    #참여 학생        
    answer=n-len(s_lost) 
    return answer
