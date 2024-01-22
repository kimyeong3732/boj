#include <cstdio>
#include <cstdlib>

int main() {
    int n;
    int xs, ys;
    int result = 0;
    int x1, x2, y1, y2;
    
    scanf("%d", &n);
    
    scanf("%d%d", &xs, &ys);
    x1 = xs;
    y1 = ys;
    
    for(int i=1; i<n; i++) {
        scanf("%d%d", &x2, &y2);
        
        result += abs(x1-x2) + abs(y1-y2);
        x1 = x2;
        y1 = y2;
    }
    
    result += abs(xs-x1) + abs(ys-y1);
    
    printf("%d\n", result);
    
    return 0;
}