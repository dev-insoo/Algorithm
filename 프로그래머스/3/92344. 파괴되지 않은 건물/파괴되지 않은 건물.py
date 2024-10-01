def solution(board, skill):
    answer = 0
    
    n = len(board)
    m = len(board[0])
    prefix_sum = [[0 for _ in range(m+1)] for _ in range(n+1)]
    for skil in skill:
        command, r1, c1, r2, c2, degree = skil
        if command == 1:
            degree = -degree
        
        prefix_sum[r1][c1] += degree
        prefix_sum[r2+1][c1] += -degree
        prefix_sum[r1][c2+1] += -degree
        prefix_sum[r2+1][c2+1] += degree
        
        
    for i in range(n):
        for j in range(m):
            prefix_sum[i][j+1] += prefix_sum[i][j] 
            
    for i in range(n):
        for j in range(m):
            prefix_sum[i+1][j] += prefix_sum[i][j] 
            
    for i in range(n):
        for j in range(m):
            board[i][j] += prefix_sum[i][j]
            if board[i][j] > 0:
                answer += 1
    
    return answer