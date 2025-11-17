#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> plus, minus;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        if(num > 0)
            plus.push_back(num);
        
        else
            minus.push_back(num);
    }
    
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());
    
    int result = 0;
    
    int i = 0;
    while(i < plus.size()) {
        if(i+1<plus.size() && plus[i]*plus[i+1]>plus[i]+plus[i+1]) {
            result += plus[i] * plus[i+1];
            i += 2;
        }
        
        else {
            result += plus[i];
            i++;
        }
    }
    
    i = 0;
    while(i < minus.size()) {
        if(i+1<minus.size() && minus[i]*minus[i+1]>minus[i]+minus[i+1]) {
            result += minus[i] * minus[i+1];
            i += 2;
        }
        
        else {
            result += minus[i];
            i++;
        }
    }
    
    cout << result;
    
    return 0;
}