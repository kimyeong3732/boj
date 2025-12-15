#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> points[2000001];

int main() {
    int n;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        points[i*2] = {a, 1};
        points[i*2+1] = {b, -1};
    }
    
    sort(points, points+n*2);
    
    int maxn = 0;
    int num = 0;
    for(int i=0; i<2*n; i++) {
        num += points[i].second;
        
        maxn = max(maxn, num);
    }
    
    cout << maxn;
    
    return 0;
}