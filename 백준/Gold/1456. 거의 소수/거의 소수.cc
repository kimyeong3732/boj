#include <iostream>

using namespace std;

bool prime[10000001];

int main() {
    long long n, m;
    int result = 0;
    
    cin >> n >> m;
    
    for(long long i=2; i*i<=m; i++)
        if(!prime[i])
            for(long long j=i+i; j<=m && j<=10000001; j+=i)
                if(!prime[j])
                    prime[j] = true;
    
    for(long long i=2; i*i<=m; i++) {
        if(!prime[i]) {
            for(long long j=i*i; j<=m; j*=i) {
                if(j >= n)
                    result++;
                
                if(j > m/i)
                    break;
            }
        }
    }
    
    cout << result;
    
    return 0;
}