def DFS(edges, visited, s):
    visited[s] = 1
    
    for i in range(len(edges[s])):
        if edges[s][i]==1 and visited[i]==0:
            DFS(edges, visited, i)

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n, m = map(int, input().split())
    edge = [[0 for i in range(n)] for i in range(n)]
    visit = [0 for i in range(n)]
    result = 0
    
    for i in range(m):
        a, b = map(int, input().split())
        edge[a-1][b-1] = 1
        edge[b-1][a-1] = 1
    
    for i in range(n):
        if visit[i] == 0:
            DFS(edge, visit, i)
            result += 1
            
    print('#' + str(test_case), result)