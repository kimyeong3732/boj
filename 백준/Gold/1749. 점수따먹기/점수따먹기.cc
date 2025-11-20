#include <iostream>

using namespace std;

int main() {
    int n, m;
    int input[200][200];
    int temp[200];
    int result = -10000;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> input[i][j];
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            temp[j] = 0;
        
        for(int j=i; j<m; j++) {
            for(int k=0; k<n; k++)
                temp[k] += input[k][j];
            
            int num = temp[0];
                
            result = max(result, num);
            
            for(int k=1; k<n; k++) {
                num = max(temp[k], num+temp[k]);
                
                result = max(result, num);
            }
            
        }
    }
    
    cout << result;
    
    return 0;
}