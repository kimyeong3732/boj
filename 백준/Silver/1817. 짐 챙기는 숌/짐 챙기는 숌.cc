#include <iostream>

using namespace std;

int main() {
    int n, m;
    int result = 0;
    
    cin >> n >> m;
    
    if(n > 0) {
        result++;
    }
    
    int temp = 0;
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        if(temp+num > m) {
            temp = 0;
            result++;
        }
        
        temp += num;
    }
    
    cout << result;
    
    return 0;
}