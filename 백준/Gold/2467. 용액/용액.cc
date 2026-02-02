#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int l=0, r=v.size()-1;
    int result = 2000000001;
    int lr, rr;
    
    while(l < r) {
        int d = v[l] + v[r];
        
        int check = d;
        
        if(check < 0)
            check *= -1;
        
        if(check < result) {
            result = check;
            lr = l;
            rr = r;
        }
        
        if(d > 0)
            r--;
        
        if(d < 0)
            l++;
        
        if(d == 0)
            break;
    }
    
    cout << v[lr] << " " << v[rr];
    
    return 0;
}