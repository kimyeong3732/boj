#include <cstdio>
#include <algorithm>
using namespace std;

struct time {
    int begin;
    int end;
};

bool cmp(time a, time b) {
    if(a.end == b.end)
        return a.begin < b.begin;
    return a.end < b.end;
}

int main() {
    int n;
    time t[100000];
    int count = 1, preend;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d%d", &t[i].begin, &t[i].end);
    
    sort(t, t+n, cmp);
    
    preend = t[0].end;
    
    for(int i=1; i<n; i++) {
        if(preend <= t[i].begin) {
            count++;
            preend = t[i].end;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}