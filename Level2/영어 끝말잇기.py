def solution(n, words):
    answer = []
    check=[words[0]]
    for i in range(1,len(words)):
        if words[i] in check:
                answer.append((i%n)+1)
                answer.append((i//n)+1)
                break
        elif words[i][0]==check[i-1][-1]:
            check.append(words[i])
        else:
            answer.append((i%n)+1)
            answer.append((i//n)+1)
            break
    if not answer:
        answer.append(0)
        answer.append(0)
    return answer
