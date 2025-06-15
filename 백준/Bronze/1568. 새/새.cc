#include <iostream>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int time = 0;
    int k = 1;
    
    while(n > 0) {
        if(n < k)
            k = 1;
        
        n -= k;
        k++;
        time++;
    }
    
    cout << time;
    
    return 0;
}