def solution(priorities, location):
    answer=0
    
    #우선순위 리스트가 비어질때까지
    while (len(priorities)!=0):
        #제일 첫번째이면
        if location==0:
            
            if priorities[0] < max(priorities):
                priorities.append(priorities.pop(0))
                location=len(priorities)-1
            else:
                return answer+1
        #그 외
        else:
            if priorities[0]<max(priorities):
                priorities.append(priorities.pop(0))
                location-=1
            else:
                priorities.pop(0)
                location-=1
                answer+=1