#include <iostream>

using namespace std;

int main() {
    long long n, m;
    
    cin >> n >> m;
    
    long long c = 0;
    int r = -1;
    long long digit = 1;
    long long start = 1;
    long long nc = 9;
    
    while(m>c+nc*digit && n>=start+nc-1) {
        c += nc * digit;
        digit++;
        start *= 10;
        nc *= 10;
    }
    
    for(start; start<=n; start++) {
        if(m <= c+digit) {
            int num = start;
            string s = "";
            
            while(num > 0) {
                s = (char)(num%10 + '0') + s;
                
                num /= 10;
            }
        
            r = s[m-c-1] - '0';
            break;
        }
        
        c += digit;
    }
    
    cout << r;
    
    return 0;
}