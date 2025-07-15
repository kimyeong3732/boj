#include <iostream>

using namespace std;

bool check(int a) {
    for(int i=a; i>0; i/=10)
        if(i%10!=4 && i%10!=7)
            return false;
    
    return true;
}

int main() {
    int n;
    
    cin >> n;
    
    int result = 0;
    
    for(int i=1; i<=n; i++)
        if(check(i))
            result = i;
    
    cout << result;
    
    return 0;
}