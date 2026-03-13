#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    int result[3] = {0, 0, 0};
    int r[100000];
    int g[100000];
    int b[100000];
    
    cin >> n >> s;
    
    for(int i=0; i<n; i++) {
        if(s[i] == 'R')
            r[i] = g[i] = b[i] = 0;
        
        else if(s[i] == 'G')
            r[i] = g[i] = b[i] = 1;
        
        else
            r[i] = g[i] = b[i] = 2;
    }
        
    
    for(int i=0; i<n-2; i++) {
        if(r[i] != 0) {
            if(r[i] == 1) {
                r[i] = (r[i] + 2) % 3;
                r[i+1] = (r[i+1] + 2) % 3;
                r[i+2] = (r[i+2] + 2) % 3;
                
                result[0] += 2;
            }
            
            else {
                r[i] = (r[i] + 1) % 3;
                r[i+1] = (r[i+1] + 1) % 3;
                r[i+2] = (r[i+2] + 1) % 3;
                
                result[0] += 1;
            }
        }
        
        if(g[i] != 1) {
            if(g[i] == 2) {
                g[i] = (g[i] + 2) % 3;
                g[i+1] = (g[i+1] + 2) % 3;
                g[i+2] = (g[i+2] + 2) % 3;
                
                result[1] += 2;
            }
            
            else {
                g[i] = (g[i] + 1) % 3;
                g[i+1] = (g[i+1] + 1) % 3;
                g[i+2] = (g[i+2] + 1) % 3;
                
                result[1] += 1;
            }
        }
        
        if(b[i] != 2) {
            if(b[i] == 0) {
                b[i] = (b[i] + 2) % 3;
                b[i+1] = (b[i+1] + 2) % 3;
                b[i+2] = (b[i+2] + 2) % 3;
                
                result[2] += 2;
            }
            
            else {
                b[i] = (b[i] + 1) % 3;
                b[i+1] = (b[i+1] + 1) % 3;
                b[i+2] = (b[i+2] + 1) % 3;
                
                result[2] += 1;
            }
        }
    }
    
    if(r[n-2]!=0 || r[n-1]!=0)
        result[0] = -1;
    
    if(g[n-2]!=1 || g[n-1]!=1)
        result[1] = -1;
    
    if(b[n-2]!=2 || b[n-1]!=2)
        result[2] = -1;
    
    int answer = result[0];
    
    for(int i=1; i<3; i++) {
        if(result[i] >= 0) {
            if(answer < 0)
                answer = result[i];
            
            answer = min(answer, result[i]);
        }
    }
    
    cout << answer;
    
    return 0;
}