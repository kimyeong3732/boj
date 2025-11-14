#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int result = 0;
    
    for(int i=0; i<n; i++) {
        int l = 0;
        int r = n - 1;
        
        while(l < r) {
            if(l == i) {
                l++;
                continue;
            }
            
            if(r == i) {
                r--;
                continue;
            }
            
            if(v[l]+v[r] < v[i]) {
                l++;
            }
            else if(v[l]+v[r] > v[i]) {
                r--;
            }
            else {
                result++;
                break;
            }
        }
    }
    
    cout << result;
    
    return 0;
}