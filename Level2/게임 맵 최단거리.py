from collections import deque

#상하좌우
dy=[-1,1,0,0]
dx=[0,0,-1,1]

#너비우선탐색
def BFS(maps, dist, n, m):
    q=deque()
    q.append([0,0])
    dist[0][0]=1;
    
    while q:
        cy,cx=q.popleft()
        
        #상하좌우 탐색
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            
            #범위내
            if 0<= ny < n and 0<= nx < m and maps[ny][nx] == 1:
                #미방문이고 벽이 아닌 경우
                if dist[ny][nx] == -1:
                    dist[ny][nx] = dist[cy][cx] + 1            
                    q.append([ny,nx])

def solution(maps):
    answer = 0
    
    #가로 세로 길이
    n = len(maps)
    m = len(maps[0])
    
    #거리 정보를 담는 리스트
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    
    #너비우선탐색으로 거리정보를 담음
    BFS(maps,dist, n, m)
    answer = dist[-1][-1]
    
    #반환
    return answer