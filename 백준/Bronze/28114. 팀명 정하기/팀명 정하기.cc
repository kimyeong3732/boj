#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int y[3];
    pair<int, string> p[3];
    
    for(int i=0; i<3; i++) {
        int n, yy;
        string s;
        
        cin >> n >> yy >> s;
        
        y[i] =yy % 100;
        p[i] = make_pair(n, s);
    }
    
    sort(y, y+3);
    sort(p, p+3);
    
    for(int i=0; i<3; i++)
        cout << y[i];
    
    cout << "\n";
    
    for(int i=2; i>=0; i--)
        cout << p[i].second[0];
    
    return 0;
}