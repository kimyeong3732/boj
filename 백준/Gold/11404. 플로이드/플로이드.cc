#include <iostream>
#include <algorithm>
using namespace std;

int arr[100][100];

int main() {
    int n, m;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = 10000001;
        }
    }
    
    for(int i=0; i<m; i++) {
        int start, end, cost;
        
        cin >> start >> end >> cost;
        
        arr[start - 1][end - 1] = min(arr[start - 1][end - 1], cost);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j] == 10000001)
                arr[i][j] = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout << arr[i][j] << ' ';
            
        cout << '\n';
    }
    
    return 0;
}