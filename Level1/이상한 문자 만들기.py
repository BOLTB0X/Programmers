#이상한 문자 만들기
s="try hello world"
def solution(s):
    answer=[]
    ss=s.split(' ') #받은 문자열을 공백으로 나눠 리스트로 변경
    for x in ss:
        sss='' #각 단어의 인덱스로 해야하므로
        for i in range(len(x)):
            if i%2==0:
                sss+=x[i].upper()
            else:
                sss+=x[i].lower()
        answer.append(sss)
    return ' '.join(answer)
print(solution(s))
#https://programmers.co.kr/learn/courses/30/lessons/12930