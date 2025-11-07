#include <iostream>

using namespace std;

bool rest[100000];

int main() {
    long long n, k;
    
    cin >> n >> k;
    
    long long temp = n;
    int digit = 0;
    
    while(temp > 0) {
        digit++;
        temp /= 10;
    }
    
    int count = 1;
    long long r = n % k;
    
    while(r!=0 && !rest[r]) {
        rest[r] = true;
        
        for(int i=0; i<digit; i++)
            r *= 10;
        
        r += n;
        
        r %= k;
        
        count++;
    }
    
    if(r != 0)
        count = -1;
    
    cout << count;
    
    return 0;
}