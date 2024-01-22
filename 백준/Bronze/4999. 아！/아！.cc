#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char a[1001];
    char b[1001];
    
    scanf("%s%s", a, b);
    
    if(strlen(a) < strlen(b))
       printf("no\n");
    else
        printf("go\n");
    
    return 0;
}