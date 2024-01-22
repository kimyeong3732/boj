#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int s1[4], s2[2];
    
    for(int i=0; i<4; i++)
        scanf("%d", s1+i);
    
    for(int i=0; i<2; i++)
        scanf("%d", s2+i);
    
    sort(s1, s1+4);
    sort(s2, s2+2);
    
    printf("%d\n", s1[1]+s1[2]+s1[3]+s2[1]);
    
    return 0;
}