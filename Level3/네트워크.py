#깊이 우선 탐색
def DFS(computers, visited, start):
    visited[start] = True

    for i in range(len(computers)):
        if visited[i] == True:
            continue
        if computers[start][i] == 0:
            continue
        DFS(computers,visited,i)

def solution(n, computers):
    answer = 0
    #방문리스트 
    visited = [False] * len(computers)

    for i in range(n):
        if visited[i] == False:
            answer+=1
            DFS(computers,visited,i)
    return answer