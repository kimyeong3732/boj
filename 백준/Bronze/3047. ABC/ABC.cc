#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];
    char ch[4];
    
    scanf("%d%d%d", arr, arr+1, arr+2);
    scanf("%s", ch);
    
    sort(arr, arr+3);
    
    for(int i=0; i<3; i++)
        printf("%d ", arr[ch[i]-'A']);
    
    printf("\n");
    
    return 0;
}