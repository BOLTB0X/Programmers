def solution(left,right):
    answer=[]
    nums=[i for i in range(left,right+1)] #left와 right 사이 값들을 담는 리스트
    for num in nums: #검사시작
        cnt=0 #num이 바뀔때마다 cnt 초기화
        for i in range(1,num+1): #약수 개수 확인 시작
            if num%i==0:
                cnt+=1
        if cnt%2!=0: #약수의 수가 홀수면
            answer.append(-num)
        else:
            answer.append(num)
    return sum(answer) #리스트의 총합 반환
left=13
right=17
print(solution(left,right))

##다른 사람풀이
def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if int(i**0.5)==i**0.5:
            answer -= i
        else:
            answer += i
    return answer

#https://programmers.co.kr/learn/courses/30/lessons/77884
