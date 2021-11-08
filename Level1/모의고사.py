def solution(answers):
    #각 답안 패턴 저장
    ans1=[1,2,3,4,5]
    ans2=[2,1,2,3,2,4,2,5]
    ans3=[3,3,1,1,2,2,4,4,5,5]
    score=[0,0,0]
    answer=[]
    
    for idx,ans in enumerate(answers):
        if ans==ans1[idx%len(ans1)]:
            score[0]+=1
        if ans==ans2[idx%len(ans2)]:
            score[1]+=1
        if ans==ans3[idx%len(ans3)]:
            score[2]+=1
    
    #각 수포자들이 맞은지 체크
    for idx,each in enumerate(score):
        #점수가 최고점이면
        if each==max(score):
            answer.append(idx+1)
    
    #반환
    return answer
