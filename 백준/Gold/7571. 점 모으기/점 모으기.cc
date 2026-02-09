#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector<long long> x;
    vector<long long> y;
    
    for(int i=0; i<m; i++) {
        long long a, b;
        
        cin >> a >> b;
        
        x.push_back(a);
        y.push_back(b);
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    long long xm = x[m/2];
    long long ym = y[m/2];
    long long result = 0;
    
    for(int i=0; i<m; i++) {
        long long xt = x[i] - xm;
        long long yt = y[i] - ym;
        
        if(xt < 0)
            xt *= -1;
        
        if(yt < 0)
            yt *= -1;
        
        result += xt + yt;
    }
    
    cout << result;
    
    return 0;
}