#include <iostream>
#include <map>

using namespace std;

long long n, p, q, x, y;
map<long long, long long> m;

long long find(long long num) {
    if(num <= 0)
        return 1;
    
    if(m.find(num) != m.end())
        return m[num];
    
    return m[num] = find(num/p-x) + find(num/q-y);
}

int main() {
    cin >> n >> p >> q >> x >> y;
    
    cout << find(n);
    
    return 0;
}