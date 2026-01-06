#include <iostream>
#include <vector>
#include <algorithm>

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
    
    int result = -1;
    
    for(int i=1; i<n-1; i++) {
        int avg = v[0] + v[i] + v[i+1];
        int temp = avg - 3 * v[i];
        
        if(temp < 0)
            temp *= -1;
        
        result = max(result, temp);
    }
    
    for(int i=0; i<n-2; i++) {
        int avg = v[n-1] + v[i] + v[i+1];
        int temp = avg - 3 * v[i+1];
        
        if(temp < 0)
            temp *= -1;
        
        result = max(result, temp);
    }
    
    cout << result;
    
    return 0;
}