#include <iostream>

using namespace std;

bool prime[4000001];

bool check(int a, int b) {
    int n = a;
    
    while(n > 0) {
        if(n%10 == b)
            return true;
        n /= 10;
    }
    
    return false;
}

int main() {
    int a, b, d;
    int result = 0;
    prime[1] = true;
    
    cin >> a >> b >> d;
    
    for(int i=2; i<=b; i++) {
        if(!prime[i]) {
            if(i>=a && check(i, d))
                result++;
            
            for(int j=i*2; j<=b; j+=i)
                prime[j] = true;
        }
    }
    
    cout << result;
    
    return 0;
}