#include <iostream>

using namespace std;

int main() {
    long long num;
    long long div = 10;
    string state = "NO";
    
    cin >> num;
    
    while(div <= num) {
        long long a = num / div;
        long long b = num % div;
        
        long long ar = 1;
        long long br = 1;
        
        while(a > 0) {
            ar *= a % 10;
            a /= 10;
        }
        
        for(int i=div; i>1; i/=10) {
            br *= b % 10;
            b /= 10;
        }
        
        if(ar == br) {
            state = "YES";
            break;
        }
        
        div *= 10;
    }
    
    cout << state;
    
    return 0;
}