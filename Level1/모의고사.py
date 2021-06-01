answers=[1,3,2,4,2]
def solution(answers):
    ans1 = [1,2,3,4,5]
    ans2 = [2,1,2,3,2,4,2,5]
    ans3 = [3,3,1,1,2,2,4,4,5,5]
    score= [0,0,0]
    answer=[]
    for index,ans in enumerate(answers): #(index,ans)
        if ans==ans1[index%len(ans1)]: #ex) index=1==>answer[1]==ans1[1%5==1] 으로 순환된다.
            score[0]+=1
        if ans==ans2[index%len(ans2)]:
            score[1]+=1
        if ans==ans3[index%len(ans3)]:
            score[2]+=1
    for i,each in enumerate(score): #이제 수포자들이 맞은 수를 체크
        if each == max(score): #점수가 최고점이면
            answer.append(i+1) #수포자 번호(+1)를 정답리스트에 추가
    return answer
print(solution(answers))