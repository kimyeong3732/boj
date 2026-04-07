#include <iostream>

using namespace std;

bool divnum[500001];
bool prime[500001];

int main() {
    long long n;
    
    cin >> n;
    
    for(int i=1; i<=n/2; i++) {
        if(n%i == 0) {
            divnum[i] = true;
            divnum[n/i] = true;
        }
    }
    
    for(int i=2; i*i<=n; i++)
        if(!prime[i])
            for(int j=i*2; j<=n; j+=i)
                prime[j] = true;
    
    long long a, b=0, c=0;
    
    if(n%2 == 0)
        a = (n/2) * (n/2 - 1);
    
    else
        a = (n/2) * (n/2);
    
    cout << a << "\n";
    
    for(int i=1; i<=n/2; i++)
        if(divnum[i])
            for(int j=i; j<=n/2; j++)
                if(divnum[j] && divnum[i+j])
                    b++;
    
    cout << b << "\n";
    
    for(int i=3; i<=n-2; i++)
        if(!prime[i] && !prime[i+2])
            c++;
    
    cout << c << "\n";
    
    return 0;
}