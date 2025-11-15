#include <iostream>
#include <algorithm>

using namespace std;

int alpha[26];

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        int digit = 1;
        
        for(int j=s.size()-1; j>=0; j--) {
            alpha[s[j] - 'A'] += digit;
            digit *= 10;
        }
    }
    
    sort(alpha, alpha+26, greater<int>());
    
    int result = 0;
    
    for(int i=0; i<10; i++)
        result += alpha[i] * (9 - i);
    
    cout << result;
    
    return 0;
}