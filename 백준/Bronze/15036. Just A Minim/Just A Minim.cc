#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double result = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a;
        
        cin >> a;
        
        if(a == 0)
            result += 2.0;
        
        else
            result += 1 / (double) a;
    }
    
    cout << fixed << setprecision(4) << result;
    
    return 0;
}