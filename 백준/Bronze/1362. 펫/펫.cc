#include <iostream>

using namespace std;

int main() {
    int o, w;
    int t = 1;
    
    cin >> o >> w;
    
    while(o!=0 && w!=0) {
        char c;
        int n;
        
        cin >> c >> n;
        
        while(c != '#') {
            if(w > 0) {
                if(c == 'E')
                    w -= n;
                else
                    w += n;
            }
            
            cin >> c >> n;
        }
        
        if(w <= 0)
            cout << t << " RIP\n";
        else if(w>(o/2) && w<(o*2))
            cout << t << " :-)\n";
        else
            cout << t << " :-(\n";
        
        cin >> o >> w;
        t++;
    }
    
    return 0;
}