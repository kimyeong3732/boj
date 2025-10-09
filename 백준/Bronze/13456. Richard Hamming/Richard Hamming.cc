#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int nn;
        int a[50], b[50];
        
        cin >> nn;
        
        for(int j=0; j<nn; j++)
            cin >> a[j];
        
        for(int j=0; j<nn; j++)
            cin >> b[j];
        
        int r = 0;
        
        for(int j=0; j<nn; j++)
            if(a[j] != b[j])
                r++;
        
        cout << r << "\n";
    }
    
    return 0;
}