#include <iostream>
#include <unordered_map>

using namespace std;

long long n, p, q;
unordered_map<long long, long long> um;

long long find(long long num) {
    if(um.find(num) != um.end())
        return um[num];
    
    return um[num] = find(num/p) + find(num/q);
}

int main() {
    cin >> n >> p >> q;
    
    um[0] = 1;
    
    if(n == 0)
        cout << 1;
    
    else
        cout << find(n/p) + find(n/q);
    
    return 0;
}