#include <iostream>

using namespace std;

void draw(int n) {
    int num = 4 * n - 3;
    int c = 0;
    bool state = false;
    
    for(int i=0; i<num; i++) {
        if(!state && i%2==1)
            c++;
        
        if(c == n) {
            state = true;
            c--;
        }
        
        for(int j=0; j<c; j++)
            cout << "* ";
        
        for(int j=0; j<num-(4*c); j++) {
            if(i%2 == 1)
                cout << " ";
            
            else
                cout << "*";
        }
        
        for(int j=0; j<c; j++)
            cout << " *";
        
        cout << "\n";
        
        if(state && i%2==1)
            c--;
    }
}

int main() {
    int n;
    
    cin >> n;
    
    draw(n);
    
    return 0;
}