#수박수박수박수박수박수?
def solution(n):
    answer=''
    st='수박'*10000
    answer +=st[:n]
    return answer
n=4
print(solution(n))