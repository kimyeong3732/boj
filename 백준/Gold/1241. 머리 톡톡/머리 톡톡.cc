#include <iostream>
#include <vector>

using namespace std;

int count[1000001];

int main() {
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        v.push_back(temp);
        count[temp]++;
    }
    
    for(int i=0; i<n; i++) {
        int r = 0;
        
        for(int j=1; j*j<=v[i]; j++) {
            if(v[i]%j == 0) {
                r += count[j];
                
                if(j != v[i]/j)
                    r += count[v[i]/j];
            }
        }
        
        cout << r-1 << "\n";
    }
    
    return 0;
}