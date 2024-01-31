def rotatePrint(input_map, n):
    for i in range(n):
        num1 = ''
        num2 = ''
        num3 = ''
        
        for j in range(n):
            num1 += str(input_map[n-1-j][i]);
            num2 += str(input_map[n-1-i][n-1-j]);
            num3 += str(input_map[j][n-1-i]);
        
        print(num1, num2, num3)

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(input())
    my_map = [list(map(int, input().split())) for i in range(n)]
    
    print('#' + str(test_case))
    rotatePrint(my_map, n)
