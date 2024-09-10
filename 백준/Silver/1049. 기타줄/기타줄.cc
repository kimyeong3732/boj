#include <iostream>

using namespace std;

int main() {
    int n, m;
    int min_6=1000, min_1=1000;
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++) {
        int cost_6, cost_1;
        
        cin >> cost_6 >> cost_1;
        
        if(min_6 > cost_6) {
            min_6 = cost_6;
        }
        if(min_1 > cost_1) {
            min_1 = cost_1;
        }
    }
    
    int result = 0;
    
    if(n >= 6) {
        if(min_6 <= min_1*6) {
            result += min_6 * (n/6);
        }
        else {
            result += (min_1*6) * (n/6);
        }

        n %= 6;
    }
    
    if(n != 0) {
        if(min_6 <= min_1*n) {
            result += min_6;
        }
        else {
            result += min_1 * n;
        }
    }
    
    cout << result;
    
    return 0;
}