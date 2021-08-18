def solution(numbers):
    answer = ''
    tmp_list=[]
    for num in numbers:
        tmp_list.append(str(num))
    tmp_list.sort(key=lambda x : x*3, reverse=True)

    answer=str(int(''.join(tmp_list)))
    return answer