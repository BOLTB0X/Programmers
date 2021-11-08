def solution(a,b):
    answer=''
    #1/1은 금요일이므로
    days = ["THU","FRI","SAT","SUN","MON","TUE","WED"] 
    #달의 일수를 리스트에 저장
    month=[31, 29, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31] 
    
    #리스트에 (a-1)까지 리스트 원소들의 합
    #이제 b를 더하고 %7 값의 인덱스 번호를 answer에 넣는다.
    answer += days[(sum(month[:a - 1]) + b) % 7]
    return answer
