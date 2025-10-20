#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int a, b;
    vector<int> va, vb, r;
    
    cin >> a >> b;
    
    for(int i=0; i<a; i++) {
        int num;
        
        cin >> num;
        
        va.push_back(num);
    }
    
    for(int i=0; i<b; i++) {
        int num;
        
        cin >> num;
        
        vb.push_back(num);
    }
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    int c = 0;
    
    for(int i=0; i<a; i++) {
        while(c<b && va[i]>vb[c])
            c++;
        
        if(c>=b || va[i]!=vb[c])
            r.push_back(va[i]);
    }
    
    cout << r.size() << "\n";
    
    for(int i=0; i<r.size(); i++)
        cout << r[i] << " ";
    
    return 0;
}