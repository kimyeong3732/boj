#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        if((a+b+c)%2 == 0)
            cout << "YES\n";
        
        else
            cout << "NO\n";
    }
    
    return 0;
}