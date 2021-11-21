def solution(phone_number):
    answer=''
    cnt=0
    
    #거꾸로
    for i in range(len(phone_number)-1,-1,-1):
        #4자리만 번호로 보여야하므로 cnt로 구분 
        if cnt<4: 
            answer+=phone_number[i]
            cnt+=1
        else:
            answer+='*'
    
    #다시 거꾸로
    return answer[::-1] 
