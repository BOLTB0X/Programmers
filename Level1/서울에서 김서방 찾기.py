#서울에서 김서방 찾기
seoul=["Jane", "Kim"]
def solution(seoul):
    cnt=0
    for temp in seoul:
        if temp=='Kim':
            break
        cnt+=1
    answer = '김서방은 {}에 있다'.format(cnt)
    return answer
print(solution(seoul))