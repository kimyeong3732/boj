#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main() {
    int n;
    int arr[100];
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    for(int i=n-1; i>0; i--)
        arr[i] = arr[i] - arr[i-1];
    
    arr[0] = arr[1];
    
    int g = gcd(arr[0], arr[1]);
    
    for(int i=2; i<n; i++)
        g = gcd(arr[i], g);
    
    vector<int> v;
    
    for(int i=1; i*i<=g; i++) {
        if(g%i == 0) {
            if(i!=1 && i*i!=g)
                v.push_back(i);
            
            v.push_back(g/i);
        }
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    
    return 0;
}