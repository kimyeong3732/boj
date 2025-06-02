#include <iostream>

using namespace std;

int main() {
    int y=0, m=0;
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        y += (temp / 30) + 1;
        m += (temp / 60) + 1;
    }
    
    y *= 10;
    m *= 15;
    
    if(y < m)
        cout << "Y " << y;
    else if(m < y)
        cout << "M " << m;
    else
        cout << "Y M " << m;
    
    return 0;
}