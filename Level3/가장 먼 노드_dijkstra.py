import heapq

def solution(n, edge):
    answer = 0
    INF = int(1e9)
    
    #인접그래프 및 거리 리스트 생성
    adj_list = [[] for _ in range(n + 1)]
    dist = [1e9] * (n + 1)
    
    #무향이므로
    for e in edge:
        adj_list[e[0]].append((1,e[1]))
        adj_list[e[1]].append((1,e[0]))
    
    hq = []
    dist[1] = 0
    
    for w,v in adj_list[1]:
        heapq.heappush(hq,(w,v))
    
    while hq:
        l,cur = heapq.heappop(hq)
        
        if dist[cur] > l:
            dist[cur] = l
            
            for w,v in adj_list[cur]:
                heapq.heappush(hq,(w+l,v))
    
    max_dist = 0
    
    #최대 거리 찾기
    for d in dist:
        if d!=INF and max_dist < d:
            max_dist = d
    
    #갯수 체크
    answer = dist.count(max_dist)
    
    #반환
    return answer