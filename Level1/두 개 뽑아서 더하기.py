#두개 뽑아서 더하기
def solution(numbers):
    test_answer=[]
    for i in range(len(numbers)-1):
        for j in range(i+1,len(numbers)):
            test_answer.append(numbers[i]+numbers[j])
    answer=set(test_answer) #중복 제거
    answer=list(answer)
    answer.sort() #정렬
    return answer
numbers=list(map(int,input().split()))
print(solution(numbers))
