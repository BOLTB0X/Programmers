def solution(citations):
    answer = 0
    
    #오름 차순 정렬
    citations.sort();
    
    for i in range(len(citations)):
        h_idx = len(citations)-i
        if (h_idx <= citations[i]):
            answer=h_idx;
            break;
    
    return answer