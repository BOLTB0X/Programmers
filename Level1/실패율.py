N=5
stages=[2, 1, 2, 6, 2, 4, 3, 3]
def solution(N, stages):
    answer = {} #딕셔너리 이용
    clear_palyer=len(stages)
    for i in range(N):
        if clear_palyer>=1:
            cnt=stages.count(i+1) #i+1번째 스테이지 클리어한 넘 수 구함
            answer[i+1]=cnt/clear_palyer #실패율
            clear_palyer-=cnt #다음 스테이지는 i+1애들은 클리어 못했으므로
        else: #만약 i번째 스테이지를 클리어 못한 경우
            answer[i+1]=0
    answer = sorted(answer, key=lambda x: answer[x], reverse=True) #정렬 기준 value들의 오름차순
    return answer
print(solution(N,stages))