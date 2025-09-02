#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        v.push_back(make_pair(temp, i));
    }
    
    sort(v.begin(), v.end());
    
    int result[50];
    
    for(int i=0; i<n; i++)
        result[v[i].second] = i;
    
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    
    return 0;
}