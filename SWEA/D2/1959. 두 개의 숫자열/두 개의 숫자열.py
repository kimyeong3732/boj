def find(listL, listS, n):
    result = 0
    
    for i in range(n + 1):
        j = 0;
        numSum = 0;
        
        for Snum in listS:
            numSum += Snum * listL[j + i]
            j += 1
            
        result = max(result, numSum)
    
    return result
    
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n, m = map(int, input().split())
    
    listA = list(map(int, input().split()))
    listB = list(map(int, input().split()))
    
    print('#' + str(test_case), end=' ')
          
    if n > m:
        print(find(listA, listB, n-m))
    
    else:
        print(find(listB, listA, m-n))