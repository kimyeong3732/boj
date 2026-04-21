#include <iostream>

using namespace std;

int n;
int map[401][401];

void floyd() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                map[j][k] = min(map[j][k], map[j][i]+map[i][k]);
}

int main() {
    int m;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i != j)
                map[i][j] = 4000001;
    
    for(int i=0; i<m; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        map[a][b] = c;
    }
    
    floyd();
    
    int result = 4000001;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i != j)
                result = min(result, map[i][j]+map[j][i]);
    
    if(result == 4000001)
        result = -1;
    
    cout << result;
    
    return 0;
}