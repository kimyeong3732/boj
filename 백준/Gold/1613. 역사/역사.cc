#include <iostream>

using namespace std;

int edges[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    
    cin >> n >> k;
    
    for(int i=0; i<k; i++) {
        int a, b;
        
        cin >> a >> b;
        
        edges[a][b] = -1;
        edges[b][a] = 1;
    }
    
    for(int c=1; c<=n; c++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(edges[i][j] == 0) {
                    if(edges[i][c]==1 && edges[c][j]==1)
                        edges[i][j] = 1;
                    
                    else if(edges[i][c]==-1 && edges[c][j]==-1)
                        edges[i][j] = -1;
                }
            }
        }
    }
    
    cin >> k;
    
    for(int i=0; i<k; i++) {
        int a, b;
        
        cin >> a >> b;
        
        cout << edges[a][b] << "\n";
    }
    
    return 0;
}