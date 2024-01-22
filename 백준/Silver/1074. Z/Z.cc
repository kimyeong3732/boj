#include <cstdio>

int state = 0;

int findZ(int n, int br, int bc, int r, int c) {
    int half = 1;
    for(int i=0; i<n-1; i++)
        half *= 2;
    
    if(state == 1)
        return 0;
    
    if(n == 0) {
        if((br==r) && (bc==c)) {
            state = 1;
            return 0;
        }
        return 1;
    }
    
    if((r<br) || (r>=(br+(half*2))) || (c<bc) || (c>=(bc+(half*2))))
        return half * half * 4;
    
    return findZ(n-1, br, bc, r, c) + findZ(n-1, br, bc+half, r, c) + findZ(n-1, br+half, bc, r, c) + findZ(n-1, br+half, bc+half, r, c);
}

int main() {
    int n, r, c;
    
    scanf("%d%d%d", &n, &r, &c);
    
    printf("%d\n", findZ(n, 0, 0, r, c));
    
    return 0;
}