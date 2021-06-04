#크레인 인형뽑기 게임
board=[[0,0,0,0,0],
       [0,0,1,0,3],
       [0,2,5,0,1],
       [4,2,4,4,2],
       [3,5,1,3,1]]
moves=[1,5,3,5,1,2,1,4] #열 번호

def solution(board, moves):
    answer = 0
    basket=[] #뽑은 인형을 담는 리스트
    for move in moves: #하나씩 moves의 원소를
        for n in board: #행의 갯수만큼 반복
            if n[move-1] ==0: #비어있으면 다음 행으로
                continue
            elif n[move-1] !=0: #인형발견
                basket.append(n[move-1]) #바구니에 담는다.
                if len(basket)>1 and basket[-1]==basket[-2]: #만약 바구니에 쌓였을 때 연속으로 같은게 2개 있으면
                    basket.pop(-1)
                    basket.pop(-1)
                    answer+=2
                n[move-1]=0
                break
    return answer
print(solution(board,moves))