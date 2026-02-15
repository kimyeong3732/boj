#include <iostream>

using namespace std;

int main() {
    int num[2] = {0, 0};
    
    for(int i=0; i<2; i++) {
        string s;
        
        cin >> s;
        
        for(int j=0; j<s.size(); j++) {
            switch(s[j]) {
                case 'I':
                    if(j+1<s.size() && (s[j+1]=='V' || s[j+1]=='X'))
                        num[i] -= 1;
                    
                    else
                        num[i] += 1;
                    
                    break;
                
                case 'V':
                    num[i] += 5;
                    break;
                
                case 'X':
                    if(j+1<s.size() && (s[j+1]=='L' || s[j+1]=='C'))
                        num[i] -= 10;
                    
                    else
                        num[i] += 10;
                    
                    break;
                
                case 'L':
                    num[i] += 50;
                    break;
                
                case 'C':
                    if(j+1<s.size() && (s[j+1]=='D' || s[j+1]=='M'))
                        num[i] -= 100;
                    
                    else
                        num[i] += 100;
                    
                    break;
                
                case 'D':
                    num[i] += 500;
                    break;
                
                case 'M':
                    num[i] += 1000;
                    break;
                
                default:
                    break;
            }
        }
    }
    
    int result = num[0] + num[1];
    
    cout << result << "\n";
    
    int c = result / 1000;
    result %= 1000;
    
    for(int i=0; i<c; i++)
        cout << "M";
    
    c = result / 100;
    result %= 100;
    
    if(c%5 == 4) {
        cout << "C";
        
        if(c > 5)
            cout << "M";
        
        else
            cout << "D";
    }
    
    else {
        if(c >= 5)
            cout << "D";
        
        c %= 5;
        
        for(int i=0; i<c; i++)
            cout << "C";
    }
    
    c = result / 10;
    result %= 10;
    
    if(c%5 == 4) {
        cout << "X";
        
        if(c > 5)
            cout << "C";
        
        else
            cout << "L";
    }
    
    else {
        if(c >= 5)
            cout << "L";
        
        c %= 5;
        
        for(int i=0; i<c; i++)
            cout << "X";
    }
    
    c = result;
    
    if(c%5 == 4) {
        cout << "I";
        
        if(c > 5)
            cout << "X";
        
        else
            cout << "V";
    }
    
    else {
        if(c >= 5)
            cout << "V";
        
        c %= 5;
        
        for(int i=0; i<c; i++)
            cout << "I";
    }
    
    return 0;
}