#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) {
        int num;
        
        cin >> num;
        
        for(int j=0; j<num; j++)
            v.push_back(i);
    }
    
    for(int i=0; i<m; i++) {
        int num;
        
        cin >> num;
        
        cout << v[num] << "\n";
    }
    
    return 0;
}