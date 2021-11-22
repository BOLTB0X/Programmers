def solution(participant,completion):
    #참가자와 완주자 오름차순 정렬
    participant.sort()
    completion.sort()
    
    #정렬된 리스트들 중 
    for i in range(len(completion)):
        #다르다면
        if participant[i]!=completion[i]:
            #해당 선수가 완주하지 못한 선수
            return participant[i]

    #마지막 선수가 완주하지 못한 선수
    return participant.pop()