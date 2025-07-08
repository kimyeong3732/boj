#include <iostream>

using namespace std;

int main() {
    bool prime[10001];
    
    for(int i=2; i<10001; i++)
        prime[i] = true;
    
    for(int i=2; i<10001; i++)
        if(prime[i])
            for(int j=i*2; j<10001; j+=i)
                if(prime[j])
                    prime[j] = false;
    
    int m, n;
    int sum = 0;
    int min = -1;
    
    cin >> m >> n;
    
    for(int i=m; i<=n; i++) {
        if(prime[i]) {
            if(min < 0) {
                min = i;
            }
            
            sum += i;
        }
    }
    
    if(sum > 0)
        cout << sum << "\n";
    
    cout << min;
    
    return 0;
}