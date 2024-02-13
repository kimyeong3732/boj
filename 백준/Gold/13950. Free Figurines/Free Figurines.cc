#include <cstdio>

int before_p[100001];
int after_p[100001];
bool check[100001];

int main() {
    int n;
    
    scanf("%d", &n);
    
    int before_i[n+1];
    int after_i[n+1];
    
    for(int i=1; i<=n; i++)
        scanf("%d", before_i+i);
    for(int i=1; i<=n; i++)
        scanf("%d", after_i+i);
        
    for(int i=1; i<=n; i++) {
        before_p[before_i[i]] = i;
        after_p[after_i[i]] = i;
    }
    
    for(int i=1; i<=n; i++) {
        if(before_p[i]==0 && before_p[i]==after_p[i]) {
            int bi = i;
            int ai = i;
            while(bi!=0 && bi==ai) {
                check[bi] = true;
                bi = before_i[bi];
                ai = after_i[ai];
            }
        }
    }
    
    int count = 0;
    for(int i=1; i<=n; i++) {
        if(!check[i]) {
            count += before_p[i]!=0 ? 1 : 0;
            count += after_p[i]!=0 ? 1 : 0;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}