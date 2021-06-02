#행렬의 곱셈
arr1=[[1, 4], [3, 2], [4, 1]]
arr2=[[3, 3], [3, 3]]
# arr1(iXj) arr2(kXj)
# 곱셈은 앞 행렬의 '열'과 뒤 행렬 '행'이 같아야함
# 결과는 앞 행렬 '행' 뒤 행렬 '열'
def solution(arr1, arr2):
    answer=[[0 for _ in range(len(arr2[0]))] for _ in range(len(arr1))]
    for i in range(len(arr1)): #앞 행렬의 행개수
        for j in range(len(arr2[0])): #뒤 행렬의 열개수
            for k in range(len(arr2)): # 뒤 행렬의 행개수
                answer[i][j] += (arr1[i][k]*arr2[k][j])
    return answer
print(solution(arr1,arr2))

#https://programmers.co.kr/learn/courses/30/lessons/12949