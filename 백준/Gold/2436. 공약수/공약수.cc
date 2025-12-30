#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main() {
    int g, l;
    
    cin >> g >> l;
    
    int num = l / g;
    int ra=-1, rb=-1;
    
    for(int i=1; i*i<=num; i++) {
        if(num%i==0 && gcd(i,num/i)==1) {
            if(ra<0 || i+num/i < ra+rb) {
                ra = i;
                rb = num / i;
            }
        }
    }
    
    cout << ra*g << " " << rb*g;
    
    return 0;
}