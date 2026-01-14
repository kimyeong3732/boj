#include <iostream>
#include <algorithm>

using namespace std;

int o[300000];

int main() {
    int d, n;
    
    cin >> d >> n;
    
    for(int i=d-1; i>=0; i--) {
        cin >> o[i];
        
        if(i == d-1)
            continue;
        
        if(o[i] > o[i+1])
            o[i] = o[i+1];
    }
    
    int s = 0;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        int index = lower_bound(o+s, o+d, num) - (o + s);
        
        s += index + 1;
        
        if(s == d + 1)
            break;
    }
    
    cout << d - s + 1;
    
    return 0;
}