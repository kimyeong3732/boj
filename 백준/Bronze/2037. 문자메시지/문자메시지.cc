#include <iostream>

using namespace std;

int main() {
    int p, w;
    string s;
    int alpha[26] = {1, 1, 1,
                     2, 2, 2,
                     3, 3, 3,
                     4, 4, 4,
                     5, 5, 5,
                     6, 6, 6, 6,
                     7, 7, 7,
                     8, 8, 8, 8};
                     
    int alphat[26] = {1, 2, 3,
                     1, 2, 3,
                     1, 2, 3,
                     1, 2, 3,
                     1, 2, 3,
                     1, 2, 3, 4,
                     1, 2, 3,
                     1, 2, 3, 4};
    
    cin >> p >> w;
    getline(cin, s);
    getline(cin, s);
    
    int last = -1;
    int result = 0;
    
    for(int i=0; i<s.size(); i++) {
        int t = 1;
        
        if(s[i] != ' ') {
            int temp = s[i] - 'A';
            
            if(last == alpha[temp])
                result += w;
            
            last = alpha[temp];
            t = alphat[temp];
        }
        else {
            last = -1;
        }
        
        for(int j=0; j<t; j++)
            result += p;
    }
    
    cout << result;
    
    return 0;
}