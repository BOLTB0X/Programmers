#변환가능한지 검사
def check(cur, word):
    cnt=0
    for c,w in zip(cur,word):
        if c!=w:
            cnt+=1
        if cnt == 2:
            return False
    if cnt == 1:
        return True

#스택이용 깊이 우선 탐색
def DFS(begin, target, words, visited):
    cnt = 0;
    stack = [(begin,0)]

    #스택이 비어질때까지
    while stack:
        cur, dep = stack.pop()

        #탈출조건
        if cur == target:
            return dep

        for i in range(len(words)):
            if visited[i] == True:
                continue
            if check(cur,words[i]) == True:
                visited[i]=True
                stack.append((words[i],dep+1))
            
def solution(begin, target, words):
    answer = 0
    
    #타겟이 존재하지 않으면
    if target not in words:
        return 0
    
    #방문리스트 생성 및 초기화 
    visited = [False] * len(words)
    answer = DFS(begin,target,words,visited)

    return answer