#include <cstdio>

int map[10][10];
int count = -1;
int nums[6];

bool check(int x, int y, int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(x+j>=10 || y+i>=10 || map[y+i][x+j]==0)
                return false;
    
    return true;
}

void kill(int x, int y, int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            map[y+i][x+j] = 0;
}

void revive(int x, int y, int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            map[y+i][x+j] = 1;
}

void find(int x, int y, int rest, int cnt) {
    if(rest == 0) {
        if(count<0 || cnt<count)
            count = cnt;
        
        return;
    }
    
    int fx = -1;
    int fy = -1;
    
    for(int i=0; i<10; i++) {
        if(i < y)
            continue;
            
        for(int j=0; j<10; j++) {
            if((i==y && j<=x) || map[i][j]==0)
                continue;
            
            fx = j;
            fy = i;
            break;
        }
        
        if(fx>=0 && fy>=0)
            break;
    }
    
    
    if(nums[5]<5 && check(fx, fy, 5)) {
        kill(fx, fy, 5);
        nums[5]++;
        find(fx, fy, rest-25, cnt+1);
        revive(fx, fy, 5);
        nums[5]--;
    }
    if(nums[4]<5 && check(fx, fy, 4)) {
        kill(fx, fy, 4);
        nums[4]++;
        find(fx, fy, rest-16, cnt+1);
        revive(fx, fy, 4);
        nums[4]--;
    }
    if(nums[3]<5 && check(fx, fy, 3)) {
        kill(fx, fy, 3);
        nums[3]++;
        find(fx, fy, rest-9, cnt+1);
        revive(fx, fy, 3);
        nums[3]--;
    }
    if(nums[2]<5 && check(fx, fy, 2)) {
        kill(fx, fy, 2);
        nums[2]++;
        find(fx, fy, rest-4, cnt+1);
        revive(fx, fy, 2);
        nums[2]--;
    }
    if(nums[1]<5 && check(fx, fy, 1)) {
        kill(fx, fy, 1);
        nums[1]++;
        find(fx, fy, rest-1, cnt+1);
        revive(fx, fy, 1);
        nums[1]--;
    }
}

int main() {
    int ones = 0;
    
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            scanf("%d", &map[i][j]);
            
            if(map[i][j] == 1)
                ones++;
        }
    }
    
    find(-1, 0, ones, 0);
    
    printf("%d\n", count);
    
    return 0;
}
