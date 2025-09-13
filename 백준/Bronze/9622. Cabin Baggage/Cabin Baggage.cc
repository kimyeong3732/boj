#include <iostream>

using namespace std;

bool check(double l, double w, double d, double p) {
    if(p > 7.0)
        return false;
    
    double t = l + w + d;
    
    if((l>56.0 || w>45.0 || d>25.0) && t>125.0)
        return false;
    
    return true;
}

int main() {
    int n;
    
    cin >> n;
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        double l, w, d, p;
        
        cin >> l >> w >> d >> p;
        
        if(check(l, w, d, p)) {
            cout << 1 << "\n";
            result++;
        }
        else {
            cout << 0 << "\n";
        }
    }
    
    cout << result;
    
    return 0;
}