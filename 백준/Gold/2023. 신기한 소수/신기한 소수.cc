#include <iostream>

using namespace std;

bool check(int num) {
    for(int i=2; i*i<=num; i++)
        if(num%i == 0)
            return false;
    
    return true;
}

void find(int num, int size) {
    if(size == 1) {
        cout << num << "\n";
        return ;
    }
    
    for(int i=1; i<10; i+=2) {
        int temp = num * 10 + i;
        
        if(check(temp))
            find(temp, size-1);
    }
}

int main() {
    int n;
    int s[] = {2, 3, 5, 7};
    
    cin >> n;
    
    for(int i=0; i<4; i++) {
        find(s[i], n);
    }
    
    return 0;
}