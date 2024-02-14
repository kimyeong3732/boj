#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int totalmax = 0;

void move(int mode, int map[20][20]) {
    if(mode < 3) {
        for(int i=0; i<n; i++) {
            int temp[n];
            int index = 0;
            
            if(mode%2 == 0) {
                int last = 0;
                
                for(int j=n-1; j>=0; j--) {
                    if(map[i][j]==last && last!=0) {
                        temp[index++] = last * 2;
                        last = 0;
                    }
                    else if(map[i][j] != last) {
                        if(last == 0) {
                            last = map[i][j];
                        }
                        else if(map[i][j] != 0) {
                            temp[index++] = last;
                            last = map[i][j];
                        }
                    }
                }
                
                while(index < n) {
                    temp[index++] = last;
                    last = 0;
                }
                
                index = 0;
                for(int j=n-1; j>=0; j--)
                    map[i][j] = temp[index++];
            }
            
            else {
                int last = 0;
                
                for(int j=0; j<n; j++) {
                    if(map[i][j]==last && last!=0) {
                        temp[index++] = last * 2;
                        last = 0;
                    }
                    else if(map[i][j] != last) {
                        if(last == 0) {
                            last = map[i][j];
                        }
                        else if(map[i][j] != 0) {
                            temp[index++] = last;
                            last = map[i][j];
                        }
                    }
                }
                
                while(index < n) {
                    temp[index++] = last;
                    last = 0;
                }
                
                index = 0;
                for(int j=0; j<n; j++)
                    map[i][j] = temp[index++];
            }
        }
    }
    else {
        for(int i=0; i<n; i++) {
            int temp[n];
            int index = 0;
            
            if(mode%2 == 0) {
                int last = 0;
                
                for(int j=n-1; j>=0; j--) {
                    if(map[j][i]==last && last!=0) {
                        temp[index++] = last * 2;
                        last = 0;
                    }
                    else if(map[j][i] != last) {
                        if(last == 0) {
                            last = map[j][i];
                        }
                        else if(map[j][i] != 0) {
                            temp[index++] = last;
                            last = map[j][i];
                        }
                    }
                }
                
                while(index < n) {
                    temp[index++] = last;
                    last = 0;
                }
                
                index = 0;
                for(int j=n-1; j>=0; j--)
                    map[j][i] = temp[index++];
            }
            
            else {
                int last = 0;
                
                for(int j=0; j<n; j++) {
                    if(map[j][i]==last && last!=0) {
                        temp[index++] = last * 2;
                        last = 0;
                    }
                    else if(map[j][i] != last) {
                        if(last == 0) {
                            last = map[j][i];
                        }
                        else if(map[j][i] != 0) {
                            temp[index++] = last;
                            last = map[j][i];
                        }
                    }
                }
                
                while(index < n) {
                    temp[index++] = last;
                    last = 0;
                }
                
                index = 0;
                for(int j=0; j<n; j++)
                    map[j][i] = temp[index++];
            }
        }
    }
}

void find(int count, int map[20][20]) {
    if(count == 5) {
        int submax = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(map[i][j] > submax)
                    submax = map[i][j];
        
        if(submax > totalmax)
            totalmax = submax;
        
        return;
    }
    
    
    for(int i=1; i<=4; i++) {
        int submap[20][20];
        copy(&map[0][0], &map[0][0]+20*20, &submap[0][0]);
        move(i, submap);
        find(count+1, submap);
    }
}

int main() {
    scanf("%d", &n);
    
    int map[20][20];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);
    
    find(0, map);
    
    printf("%d\n", totalmax);
    
    return 0;
}