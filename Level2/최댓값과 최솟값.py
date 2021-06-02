#최댓값과 최솟값
s="1 2 3 4"
def solution(s):
    s=s.split(' ')
    temp=[]
    for x in s:
        temp.append(int(x))
    answer = ''
    answer+=str(min(temp))
    answer+=' '
    answer+=str(max(temp))
    return answer
print(solution(s))

#다른사람 풀이
def solution(s):
    s=list(map(int,s.split(' ')))
    return str(min(s))+' '+str(max(s))

