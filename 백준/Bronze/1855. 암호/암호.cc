#include <iostream>

using namespace std;

int main() {
    char a[20][200];
    string s;
    int n;
    
    cin >> n >> s;
    
    int n2 = s.size() / n;
    
    for(int i=0; i<s.size(); i++) {
        if((i/n)%2 == 0)
            a[i%n][i/n] = s[i];
        else
            a[(n-1)-(i%n)][i/n] = s[i];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n2; j++){
            cout << a[i][j];
        }
    }
    
    return 0;
}