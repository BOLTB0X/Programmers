def solution(triangle):
    answer = 0

    #dp테이블 초기화
    dp = [[0] * len(triangle) for _ in range(len(triangle))]

    #첫번째 수 셋팅
    dp[0][0] = triangle[0][0]

    #보텀업
    # 거쳐간 숫자의 최댓값 구하기 
    for i in range(0, len(triangle) - 1): 
        for j in range(len(triangle[i])): 
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]) 
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1])

    #정수 삼각형 최하단줄에 큰값들이 있으므로
    answer = max(dp[-1])
    return answer