#include <cstdio>

int main() {
    long long c, e, d;
    long long n;
    long long dis[1000];
    long long cost[1000];
    long long road[10000];
    long long last_cost[10000];
    
    scanf("%lld%lld%lld", &c, &e, &d);
    scanf("%lld", &n);
    
    for(int i=0; i<n; i++) {
        scanf("%lld", dis+i);
        
        if(i > 0)
            dis[i] += dis[i-1];
    }
        
    for(int i=0; i<n; i++)
        scanf("%lld", cost+i);
        
    for(int i=0; i<d; i++) {
        road[i] = -1;
        last_cost[i] = -1;
    }
    
    long long max_dis = c / e;
    long long rest = c % e;
    
    for(int i=0; i<max_dis; i++) {
        road[i] = 0;
        last_cost[i] = 0;
    }
        
    for(int i=0; i<n; i++) {
        if(road[dis[i]-1] == -1)
            break;
            
        for(int j=0; j<max_dis; j++) {
            int cur = dis[i] + j;
            
            if(cur >= d)
                break;
            
            if(last_cost[cur-1] != last_cost[cur]) {
                if(last_cost[cur]>cost[i] || (last_cost[cur-1]!=cost[i] && last_cost[cur]==-1)) {
                    last_cost[cur] = cost[i];
                    road[cur] = cost[i]>last_cost[cur-1] ? road[cur-1]+(e-rest)*last_cost[cur]+rest*last_cost[cur-1] : road[cur-1]+e*cost[i];
                }
                
                else if(last_cost[cur]==-1 && last_cost[cur-1]==cost[i]) {
                    last_cost[cur] = cost[i];
                    road[cur] = road[cur-1] + e * last_cost[cur];
                }
            }
            else if(last_cost[cur] > cost[i]) {
                last_cost[cur] = cost[i];
                road[cur] = road[cur-1] + e * last_cost[cur];
            }
        }
    }
    
    printf("%lld\n", road[d-1]);
    
    return 0;
}