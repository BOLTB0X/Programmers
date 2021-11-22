def solution(s):
    answer = []
    tran_cnt=0
    zero_cnt=0

    while True:
        if s=="1":
            break
        tmp=""
        tran_cnt+=1;

        for i in range(len(s)):
            if s[i]=="0":
                zero_cnt+=1
            else:
                tmp+="1"
        tmp_len=len(tmp)
        s=""
        while tmp_len > 0:
            s += str(tmp_len%2)
            tmp_len //= 2
        sorted(s,reverse=True)
    answer.append(tran_cnt)
    answer.append(zero_cnt)
    return answer
print(solution("1111111"))