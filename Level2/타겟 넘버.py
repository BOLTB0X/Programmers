answer = 0
def DFS(numbers,tot,target,idx):
    global answer
    n = len(numbers)
    
    if idx == n and tot == target:
        answer+=1
        return
    if idx == n:
        return

    DFS(numbers,tot+numbers[idx],target,idx+1)
    DFS(numbers,tot-numbers[idx],target,idx+1)

def solution(numbers, target):
    global answer
    DFS(numbers,0,target,0)
    return answer