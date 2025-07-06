#include <iostream>

using namespace std;

bool fire[2000000];

int main() {
    int n, t;
    
    cin >> n >> t;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        int sum = num - 1;
        
        while(sum <= t) {
            if(!fire[sum])
                fire[sum] = true;
            
            sum += num;
        }
    }
    
    int result = 0;
    
    for(int i=0; i<t; i++)
        if(fire[i])
            result++;
    
    cout << result;
    
    return 0;
}