#로또의 최고 순위와 최저 순위
lottos=[44, 1, 0, 0, 31, 25]
win_nums=[31, 10, 45, 1, 6, 19]
def solution(lottos, win_nums):
    answer = []
    cnt2=0 #최저 순위 체크 변수
    for lotto in lottos:
        if lotto in win_nums: #몇 개 맞나 확인
            cnt2+=1
    cnt1=cnt2+lottos.count(0) #최고 순위는 최저+'0'의 갯수
    if cnt1==6:
        answer.append(1)
    elif cnt1==5:
        answer.append(2)
    elif cnt1==4:
        answer.append(3)
    elif cnt1 == 3:
        answer.append(4)
    elif cnt1==2:
        answer.append(5)
    elif cnt1<=1:
        answer.append(6)
    if cnt2==6:
        answer.append(1)
    elif cnt2==5:
        answer.append(2)
    elif cnt2==4:
        answer.append(3)
    elif cnt2 == 3:
        answer.append(4)
    elif cnt2==2:
        answer.append(5)
    elif cnt2<=1:
        answer.append(6)
    return answer
print(solution(lottos,win_nums))