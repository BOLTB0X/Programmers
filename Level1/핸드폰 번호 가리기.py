#핸드폰 번호 가리기
phone_number="01033334444"
def solution(phone_number):
    answer=''
    cnt=0
    for i in range(len(phone_number)-1,-1,-1): #거꾸로
        if cnt<4: #4자리만 번호로 보여야하므로 cnt로 구분
            answer+=phone_number[i]
            cnt+=1
        else:
            answer+='*'
    return answer[::-1] #다시 거꾸로

##다른 사람의 풀이
def hide_numbers(s):
    return "*"*(len(s)-4) + s[-4:]
print(solution(phone_number))