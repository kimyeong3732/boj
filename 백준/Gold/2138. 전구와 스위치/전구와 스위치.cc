#include <iostream>

using namespace std;

int main() {
    int n;
    string a, b;
    
    cin >> n;
    cin >> a >> b;
    
    int result = 100001;
    
    int c1=1, c2=0;
    string temp1=a, temp2=a;
    
    temp1[0] = temp1[0]=='0' ? '1' : '0';
    temp1[1] = temp1[1]=='0' ? '1' : '0';
    
    for(int i=1; i<n; i++) {
        if(temp1[i-1] != b[i-1]) {
            temp1[i-1] = temp1[i-1]=='0' ? '1' : '0';
            temp1[i] = temp1[i]=='0' ? '1' : '0';
            
            if(i < n-1)
                temp1[i+1] = temp1[i+1]=='0' ? '1' : '0';
            
            c1++;
        }
        
        if(temp2[i-1] != b[i-1]) {
            temp2[i-1] = temp2[i-1]=='0' ? '1' : '0';
            temp2[i] = temp2[i]=='0' ? '1' : '0';
            
            if(i < n-1)
                temp2[i+1] = temp2[i+1]=='0' ? '1' : '0';
            
            c2++;
        }
    }
    
    if(temp1[n-1] == b[n-1])
        result = min(result, c1);
    
    if(temp2[n-1] == b[n-1])
        result = min(result, c2);
    
    if(result > 100000)
        result = -1;
    
    cout << result;
    
    return 0;
}