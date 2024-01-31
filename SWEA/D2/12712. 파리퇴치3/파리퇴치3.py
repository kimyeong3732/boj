def kill(n, m, input_map, x, y):
    result = input_map[y][x]
    
    shape_t = 0
    dx_t = (1, -1, 0, 0)
    dy_t = (0, 0, 1, -1)
    
    shape_x = 0
    dx_x = (1, 1, -1, -1)
    dy_x = (1, -1, 1, -1)
    
    for i in range(1, m):
        for j in range(4):
            nx_t = x + dx_t[j] * i
            ny_t = y + dy_t[j] * i
            
            if nx_t >= 0 and nx_t < n and ny_t >= 0 and ny_t < n:
                shape_t += input_map[ny_t][nx_t]
            
            nx_x = x + dx_x[j] * i
            ny_x = y + dy_x[j] * i
            
            if nx_x >=0 and nx_x < n and ny_x >= 0 and ny_x < n:
                shape_x += input_map[ny_x][nx_x]
    
    return result + max(shape_t, shape_x)

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n, m = map(int, input().split())
    result = 0;
    my_map = [list(map(int, input().split())) for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            result = max(result, kill(n, m, my_map, j, i))

    print('#' + str(test_case), result)