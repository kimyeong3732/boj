#include <iostream>

using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    int result = 0;
    
    for(int i=0; i<b.size();) {
        int maxb = 0;
        
        for(int j=0; j<a.size(); j++) {
            int l = 0;
            
            while(b[i+l] == a[j+l])
                l++;
            
            maxb = max(maxb, l);
        }
        
        i += maxb;
        result++;
    }
    
    cout << result;
    
    return 0;
}