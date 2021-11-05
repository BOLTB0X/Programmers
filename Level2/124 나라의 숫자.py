def solution(n):
    numbers = [1, 2, 4]
    answer = ""

    while (n > 0):
        n -= 1
        answer = str(numbers[n % 3]) + answer
        n //=3
    return answer