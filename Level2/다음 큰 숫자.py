#다음 큰 순자
def bin_trans_count(num): #2진수 변환 후 1의 갯수 체크
    num_bin=''
    while num>=1:
        num_bin+=str(num%2)
        num//=2
    cnt=num_bin.count('1')
    return cnt
def solution(n):
    answer = 0
    i=1
    while True:
        if bin_trans_count(n)==bin_trans_count(n+i):
            answer+=n+i
            break
        else:
            i+=1
    return answer
print(solution(78))