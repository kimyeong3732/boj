#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;
    int ct = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        sum += num;
        ct += num / 2;
    }
    
    if(sum%3==0 && ct>=sum/3)
        cout << "YES";
    
    else
        cout << "NO";
    
    return 0;
}