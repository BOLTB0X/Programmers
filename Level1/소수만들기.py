#소수 만들기
def solution(num):
    answer = 0
    for i in range(len(num)):
        for j in range(i+1,len(num)):
            for k in range(j+1,len(num)):
                tot=num[i]+num[j]+num[k] #3개 선택
                if tot==2: #만약 합이 2면 소수
                    answer+=1
                for x in range(2,tot):
                    if tot%x==0: #소수가 아니므로 tot는 x의 배수
                        break
                    elif x==tot-1: #소수 판별
                        answer+=1
    return answer