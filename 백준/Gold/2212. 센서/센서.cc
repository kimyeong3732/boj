#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, d;
    vector<int> v;
    
    cin >> n >> d;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    vector<int> dist;
    
    for(int i=1; i<v.size(); i++)
        dist.push_back(v[i] - v[i-1]);
    
    sort(dist.begin(), dist.end(), greater<int>());
    
    int result = 0;
    
    for(int i=d-1; i<dist.size(); i++)
        result += dist[i];
    
    cout << result;
    
    return 0;
}