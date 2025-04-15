#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    
    int i=0, num=0;
    
    cin >> s;
    
    if(s.size() < 2) {
        num = s[0] - '0';
    }
    
    else {
        i++;
        
        for(int j=0; j<s.size(); j++) {
            num += s[j] - '0';
        }
        
        while(num >= 10) {
            i++;
            
            int temp = 0;
            
            while(num > 0) {
                temp += num % 10;
                num /= 10;
            }
            
            num = temp;
        }
    }
    
    cout << i << "\n";
    
    if(num%3==0)
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}