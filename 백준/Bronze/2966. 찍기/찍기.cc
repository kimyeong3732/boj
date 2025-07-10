#include <iostream>

using namespace std;

int main() {
    int n;
    char a[3] = {'A', 'B', 'C'};
    char b[4] = {'B', 'A', 'B', 'C'};
    char c[6] = {'C', 'C', 'A', 'A', 'B', 'B'};
    string s;
    int ar=0, br=0, cr=0;
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++) {
        if(s[i] == a[i%3])
            ar++;
        
        if(s[i] == b[i%4])
            br++;
        
        if(s[i] == c[i%6])
            cr++;
    }
    
    int max = ar;
    
    if(max < br)
        max = br;
    
    if(max < cr)
        max = cr;
    
    cout << max << "\n";
    
    if(max == ar)
        cout << "Adrian\n";
    
    if(max == br)
        cout << "Bruno\n";
    
    if(max == cr)
        cout << "Goran\n";
    
    return 0;
}