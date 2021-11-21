def solution(arr1, arr2):
    #정답 벡터
    answer = [[] for _ in range(len(arr1))]
    
    #하나씩 더해줌
    for i in range(len(arr1)):
        for j in range(len(arr1[0])):
            answer[i].append(arr1[i][j]+arr2[i][j])
    
    #반환
    return answer