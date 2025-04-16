#include <iostream>

using namespace std;

int main() {
    int n, num;
    int arr[9];
    
    for(int i=0; i<9; i++)
        arr[i] = 0;
    
    cin >> n;
    
    num = n;
    
    while(num > 0) {
        int temp = num % 10;
        
        if(temp == 9)
            temp = 6;
        
        arr[temp]++;
        num /= 10;
    }
    
    int max = 0;
    
    for(int i=0; i<9; i++) {
        int c = arr[i];
        
        if(i == 6)
            c = (c + 1) / 2;
        
        if(c > max)
            max = c;
    }
    
    cout << max;
    
    return 0;
}