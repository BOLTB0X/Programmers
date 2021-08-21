def solution(brown, yellow):
    answer = []
    width=brown + yellow
    for i in range((width//2),0,-1):
        if width%i == 0:
            row = i
            col = width//i
            if (row-2)*(col-2) == yellow:
                answer.append(row)
                answer.append(col)
                break
    return answer
