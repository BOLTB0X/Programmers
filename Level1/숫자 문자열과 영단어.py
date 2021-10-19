def solution(s):
    answer = 0

    alp = {
    'zero' : 0,
    'one' : 1,
    'two' : 2,
    'three' : 3,
    'four' : 4,
    'five' : 5,
    'six' : 6,
    'seven' : 7,
    'eight' : 8,
    'nine' : 9
    }

    result=''
    k=''

    for i in s:
        if (i.isdigit()):
            result += i
        elif i.isalpha():
            k+=i;
            if (k in alp.keys()):
                result += str(alp[k])
                k=''
    answer = int(result)
    return answer