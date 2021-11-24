def solution(s):
    answer = 0
    #임시 길이
    n = len(s)
    #1 ~ len까지 압축했을때 길이 값
    compression_len_list = []
    
    #반까지만 절반의 길이까지 되는 경우는 s의 길이가 최소 2일때
    for split_size in range(1, n//2 + 1):
        compressed = ""
        #문자열 슬라이싱 이용
        splited = [s[i:i+split_size] for i in range(0, n, split_size)]
        cnt = 1
    
        for j in range(1,len(splited)):
            prev,cur = splited[j - 1],splited[j]
        
            if prev == cur:
                cnt += 1
            
            #이전 문자와 다르면
            else:
                if cnt > 1:
                    compressed += (str(cnt) + prev)
                #문자가 반복되지 않아 한번만 나타난 경우 1은 생략
                else:
                    compressed += prev
                #초기화
                cnt = 1
    
        if cnt > 1:
            compressed += (str(cnt) + splited[-1])
        #문자가 반복되지 않아 한번만 나타난 경우 1은 생략
        else:
            compressed += splited[-1]
        #길이 리스트에 삽입
        compression_len_list.append(len(compressed))
    
    #정답은 최솟값
    answer = min(compression_len_list)
    
    #반환
    return answer