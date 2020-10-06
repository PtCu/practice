from collections import deque
if __name__ == "__main__":
    n, m, x, y = map(int, input().split())
    board = [[-1]*m for i in range(n)]

    x=x-1;y=y-1
    board[x][y]=0
    q = deque([(x, y)])

    def isValid(x, y):
        return x < n and x >= 0 and y < m and y >= 0
    visited = [(x, y)]
    while q:
        cur = q.popleft()
        nextPos = [(2, 1), (2, -1), (1, 2), (1, -2),
                   (-2, 1), (-2, -1), (-1, -2), (-1, 2)]
        for i in nextPos:
            nextX = cur[0]+i[0]
            nextY = cur[1]+i[1]
            if isValid(nextX, nextY):
                if not (nextX,nextY) in visited:
                    isEmpty=False
                    board[nextX][nextY] = board[cur[0]][cur[1]]+1
                    visited.append((nextX, nextY))
                    q.append((nextX, nextY))

    for i in range(n):
        for j in range(m):
            print('{:<4d}'.format(board[i][j])+" ",end="")
        print("")
