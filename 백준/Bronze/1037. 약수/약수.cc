#include <iostream>

using namespace std;

int main() {
    int n;
    int min_num = 1000000;
    int max_num = 2;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        if(min_num > num) {
            min_num = num;
        }
        if(max_num < num) {
            max_num = num;
        }
    }
    
    cout << min_num * max_num;
    
    return 0;
}