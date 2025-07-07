#include <iostream>

using namespace std;

int main() {
    int storage[50];
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        cin >> storage[i];
    
    int now = 0;
    
    for(int i=0; i<m; i++) {
        int num;
        
        cin >> num;
        
        while(true) {
            if(storage[now] >= num) {
                storage[now] -= num;
                break;
            }
            
            now = (now + 1) % n;
        }
    }
    
    int result = 0;
    
    for(int i=0; i<n; i++)
        result += storage[i];
    
    cout << result;
    
    return 0;
}