#include <iostream>

using namespace std;

int main() {
    int n, m;
    int p[10];
    int r[50];
    int minp1=50, minp2=50;
    int minn1, minn2;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> p[i];
        
        if(i>0 && minp1>p[i]) {
            minp1 = p[i];
            minn1 = i;
        }
        
        if(minp2 > p[i]) {
            minp2 = p[i];
            minn2 = i;
        }
    }
    
    int rs = 0;
    
    cin >> m;
    
    if(m < minp1) {
        r[0] = 0;
        rs++;
    }
    
    else {
        r[0] = minn1;
        m -= minp1;
        rs++;
        
        while(m >= minp2) {
            r[rs] = minn2;
            m -= minp2;
            rs++;
        }
        
        for(int i=0; i<rs; i++) {
            for(int j=n-1; j>r[i]; j--) {
                if(m >= (p[j] - p[r[i]])) {
                    m -= p[j] - p[r[i]];
                    r[i] = j;
                    
                    break;
                }
            }
        }
    }
    
    for(int i=0; i<rs; i++)
        cout << r[i];
    
    return 0;
}