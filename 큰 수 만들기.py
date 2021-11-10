def solution(number, k):
    answer = ''
    
    number_len = len(number) - k
    start = 0
    
    #완전탐색
    for i in range(number_len):
        max_num = int(number[start])
        max_idx = start
        
        #k거리만큼 떨어진 수만큼 최댓값 찾기
        for j in range(start,k+i+1):
            if (max_num < int(number[j])):
                max_num = int(number[j])
                max_idx = j

        start = max_idx+1;
        answer += str(max_num);
    return answer