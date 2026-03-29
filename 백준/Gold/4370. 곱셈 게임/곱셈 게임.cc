#include <iostream>

using namespace std;

int main() {
    long long n;
    long long mul[2] = {9, 2};
    
    while(cin >> n) {
        int i = 0;
        long long temp = 1;
        
        while(temp < n) {
            temp *= mul[i];
            i = (i+1) % 2;
        }
        
        if(i == 1)
            cout << "Baekjoon";
        
        else
            cout << "Donghyuk";
        
        cout << " wins.\n";
    }
    
    return 0;
}