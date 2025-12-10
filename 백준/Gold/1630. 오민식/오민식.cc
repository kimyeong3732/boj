#include <iostream>

using namespace std;

bool nprime[1000001];

int main() {
    long long n;
    
    cin >> n;
    
    for(long long i=2; i<=n; i++)
        if(!nprime[i])
            for(long long j=i*2; j<=n; j+=i)
                if(!nprime[j])
                    nprime[j] = true;
    
    long long result = 1;
    
    for(int i=2; i<=n; i++) {
        if(!nprime[i]) {
            long long num = i;
            
            while(num <= n)
                num *= i;
            
            num /= i;
            
            result *= num;
            
            result %= 987654321;
        }
    }
    
    cout << result;
    
    return 0;
}