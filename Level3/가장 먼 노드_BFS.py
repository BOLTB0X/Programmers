from collections import deque

#너비 우선 그래프 
def BFS(graph, dist):
    q = deque()
    dist[1] = 1
    q.append(1)

    while q:
        cur = q.popleft()

        for i in graph[cur]:
            #미방문이면
            if dist[i] == -1:
                q.append(i)
                dist[i] = dist[cur]+1

def solution(n, edge):
    answer = 0
    #거리정보를 담는 리스트
    dist = [-1 for _ in range(len(edge)+1)]
    #무향그래프
    graph = [[] for _ in range(len(edge)+1)]

    #각 엣지를 연결
    for i in range(len(edge)):
        graph[edge[i][0]].append(edge[i][1])
        graph[edge[i][1]].append(edge[i][0])
    
    #BFS 호출
    BFS(graph,dist)

    max_value = max(dist)
    #1번 노드부터 가장 먼 노드 갯수 카운트
    for d in dist:
        if d == max_value:
            answer += 1

    return answer
