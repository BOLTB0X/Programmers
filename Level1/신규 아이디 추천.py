new_id=	"=.="
def solution(new_id):
    answer = ''
    new_id=new_id.lower() #1번 조건
    for i in range(len(new_id)): #2번 조건
        if new_id[i].isalpha() or new_id[i].isdigit() or new_id[i] in ['-','_','.']:
            answer+=new_id[i]
    while '..' in answer: #3번 조건
        answer=answer.replace('..','.')
    if answer[0] == '.':  # 4번
        if len(answer)<=1:
            answer='.'
        else:
            answer=answer[1:]
    if answer[-1] == '.':   # 조건
        answer=answer[:-1]
    if len(answer)==0: # 5번 조건
        answer+='a'
    if len(answer)>=16: #6번 조건
        answer=answer[:15]
        if answer[-1]=='.':
            answer=answer[:-1]
    while len(answer) < 3: #7번 조건
        answer += answer[-1]
    return answer
print(solution(new_id))