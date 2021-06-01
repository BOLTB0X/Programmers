#기능개발
progress=[95,90,99,99,80,99]
speeds=[1,1,1,1,1,1]
def solution(progress,speeds):
    day=[] #개발기간
    answer=[] #정답 리스트
    temp=[100]*len(progress)
    for i in range(len(progress)): #먼저 개발기간 계산한다
        temp[i]-=progress[i]
        if temp[i]%speeds[i]==0:
            day.append(temp[i]//speeds[i])
        else:
            day.append((temp[i]//speeds[i])+1)
    dev=day[0] #비교변수에 첫 번째 개발기간
    cnt=1
    for j in range(1,len(day)):
        if dev>=day[j]: #그 다음 개발기간이 더 적으면 cnt+=1
            cnt+=1
        else: #개발기간이 큰것을 만나면
            answer.append(cnt) #정답 리스트에 추가
            dev=day[i] #큰 개발기간을 비교변수에 저장
            cnt=1
    answer.append(cnt) #마지막
    return answer
print(solution(progress,speeds))