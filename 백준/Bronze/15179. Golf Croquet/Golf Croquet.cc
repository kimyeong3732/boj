#include <iostream>

using namespace std;

int main() {
    string a, b;
    int n;
    string c;
    
    getline(cin, a);
    getline(cin, b);
    
    cin >> n >> c;
    
    int r[2] = {0, 0};
    
    for(int i=0; i<n; i++) {
        switch(c[i]) {
            case 'H':
                r[i%2]++;
                break;
            
            case 'D':
                r[i%2] += 2;
                
                if(r[i%2] > 7)
                    r[i%2] = 7;
                
                break;
            
            case 'O':
                r[(i+1)%2]++;
                break;
            
            default:
                break;
        }
        
        if(r[0]==7 || r[1]==7)
            break;
    }
    
    cout << a << " " << r[0] << " " << b << " " << r[1] << ". ";
    
    if(r[0] == r[1]) {
        cout << "All square.";
    }
    
    else if(r[0]==7 || r[1]==7) {
        if(r[0] == 7)
            cout << a;
            
        else
            cout << b;
        
        cout << " has won.";
    }
    
    else {
        if(r[0] > r[1])
            cout << a;
        
        else
            cout << b;
        
        cout << " is winning.";
    }
    
    return 0;
}