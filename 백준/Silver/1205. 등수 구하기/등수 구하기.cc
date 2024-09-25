#include <iostream>

using namespace std;

int main() {
    int n, s, p;
    
    cin >> n >> s >> p;
    
    int result = n==0 ? 1 : -1;
    int ss = -1;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        if(temp == s && ss < 0) {
            ss = s;
            result = i + 1;
        }
        
        if(i+1 >= p) {
            if((ss>-1 && ss==temp) || i >= p) {
                result = -1;
                break;
            }
        }
        
        if(temp < s && ss < 0) {
            result = i + 1;
            break;
        }
    }
    
    if(n < p && result == -1) {
        result = n + 1;
    }
    
    cout << result;
    
    return 0;
}