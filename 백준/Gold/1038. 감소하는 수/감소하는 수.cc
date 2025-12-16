#include <iostream>

using namespace std;

long long result = -1;
int c = 0;
int n;

void find(long long num, int size) {
    if(size == 0) {
        c++;
        
        if(c == n)
            result = num;
        
        return;
    }
    
    
    if(num == 0) {
        for(long long i=1; i<10; i++) {
            find(i, size-1);
            
            if(c == n)
                return;
        }
    }
    
    else {
        for(long long i=0; i<num%10; i++) {
            find(num*10+i, size-1);
            
            if(c == n)
                return;
        }
    }
}

int main() {
    cin >> n;
    
    if(n == 0)
        result = 0;
    
    else
        for(int i=1; i<=10; i++)
            find(0, i);
    
    cout << result;
    
    return 0;
}