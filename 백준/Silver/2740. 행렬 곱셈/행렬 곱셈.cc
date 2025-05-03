#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    int a[100][100];
    int b[100][100];
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp;
            
            cin >> temp;
            
            a[i][j] = temp;
        }
    }
    
    cin >> m >> k;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<k; j++) {
            int temp;
            
            cin >> temp;
            
            b[i][j] = temp;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            int sum = 0;
            
            for(int l=0; l<m; l++) {
                sum += a[i][l] * b[l][j];
            }
            
            cout << sum << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}