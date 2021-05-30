#체육복
def solution(n,lost,reserve):
    slost=list(set(lost)-set(reserve)) #중복제거
    sreserve=list(set(reserve)-set(lost)) #중복제거
    #여벌 기준으로 생각
    for re in sreserve:
        if re-1 in slost: #여벌의 왼쪽에 분실이 있는지 확인
            slost.remove(re-1)
        elif re+1 in slost: #여벌의 오른쪽에 분실이 있는지 확인
            slost.remove(re+1)
    return (n-len(slost)) #학생수 - 빼기 분실한 넘 == 운동가능 수
n=int(input())
lost=list(map(int,input().split())) #도난
reserve=list(map(int,input().split())) #여벌
print(solution(n,lost,reserve))