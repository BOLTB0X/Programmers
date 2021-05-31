#k번째 수
def solution(array, commands):
    answer = []
    for comm in commands:
        temp=list(array[comm[0]-1:comm[1]])
        temp.sort()
        answer.append(temp[comm[2]-1])
    return answer
array=[1,5,2,6,3,7,4]
commands=[[2,5,3],[4,4,1],[1,7,3]]
print(solution(array,commands))