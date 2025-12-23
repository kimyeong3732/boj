#include <iostream>

using namespace std;

bool nprime(long long n) {
    for(long long i=2; i*i<=n; i++)
        if(n%i == 0)
            return true;
    
    return false;
}

long long mpow(long long a, long long p) {
    long long result = 1;
    
    long long tempa = a;
    long long tempp = p;
    
    while(tempp > 0) {
        if((tempp&1) != 0)
            result = (result * tempa) % p;
        
        tempa = (tempa * tempa) % p;
        
        tempp >>= 1;
    }
    
    return result;
}

int main() {
    long long a, p;
    
    cin >> p >> a;
    
    while(a+p > 0) {
        if(nprime(p) && mpow(a,p)==a)
            cout << "yes\n";
        
        else
            cout << "no\n";
        
        cin >> p >> a;
    }
    
    return 0;
}