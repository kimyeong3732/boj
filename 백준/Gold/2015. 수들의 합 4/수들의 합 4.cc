#include <iostream>
#include <map>

using namespace std;

int sum[200001];

map<int, long long> m;

int main() {
    int n, k;
    long long result = 0;
    
    cin >> n >> k;
    
    m[0] = 1;
    
    for(int i=1; i<=n; i++) {
        int num;
        
        cin >> num;
        
        sum[i] = sum[i-1] + num;
        
        result += m[sum[i] - k];
        m[sum[i]]++;
    }
    
    cout << result;
    
    return 0;
}