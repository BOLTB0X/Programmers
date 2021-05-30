#음양 더하기
def solution(absolutes, signs):
    answer=0
    for i in range(len(absolutes)): #길이 만큼 반복, 만악 for num in absolute로 하면 for문을 한 번 더 써야함
        if signs[i]==True: #signs의 참거짓에 따라 양/음 결정
            answer+=absolutes[i]
        else:
            answer-=absolutes[i]
    return answer
absolutes=list(map(int,input().split()))
signs=input().split()
print(solution(absolutes,signs))