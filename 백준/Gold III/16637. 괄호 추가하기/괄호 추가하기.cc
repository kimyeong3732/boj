#include <cstdio>
#include <climits>

int n;
int half;
int max = INT_MIN;
char f[20];

void dfs(int cnt, int sub) {
    if(cnt == half) {
        if(max < sub)
            max = sub;
        
        return;
    }
    
    int temp = f[cnt*2] - '0';
    char oper = f[cnt*2-1];
    
    if(cnt+1 < half) {
        int temp2 = f[(cnt+1)*2] - '0';
        char oper2 = f[(cnt+1)*2-1];
        
        switch(oper2) {
        case '+':
            temp2 = temp + temp2;
            break;
        case '-':
            temp2 = temp - temp2;
            break;
        case '*':
            temp2 = temp * temp2;
        }
        
        switch(oper) {
        case '+':
            dfs(cnt+2, sub+temp2);
            break;
        case '-':
            dfs(cnt+2, sub-temp2);
            break;
        case '*':
            dfs(cnt+2, sub*temp2);
        }
    }
        
    switch(oper) {
        case '+':
            dfs(cnt+1, sub+temp);
            break;
        case '-':
            dfs(cnt+1, sub-temp);
            break;
        case '*':
            dfs(cnt+1, sub*temp);
    }
}

int main() {
    scanf("%d", &n);
    
    half = n / 2 + 1;
    
    scanf("%s", f);
    
    int sub = f[0] - '0';
    dfs(1, sub);
    
    printf("%d\n", max);
    
    return 0;
}
