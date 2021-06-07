def solution(people, limit):
    answer = 0
    people.sort()
    fir=0 #가장 가벼운 놈
    last=len(people)-1 #가장 무거운 놈
    while fir<=last:
        answer+=1 #일단 카운팅
        if people[fir]+people[last]<=limit:
            fir+=1
        last-=1 #제한선을 비교해서 맞든 안맞든 무거운넘은 대려간다
    return answer
people=[70, 50, 80, 50]
limit=100
print(solution(people,limit))