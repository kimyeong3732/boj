#include <iostream>

using namespace std;

int pow_2(int n) {
    if(n == 1)
        return 1;
        
    int result = 1;
    
    while(result < n)
        result *= 2;
        
    return result / 2;
}

int find(int num, int num2, int twos) {
    if(twos<2 || num2==0)
        return ((num % twos) + 1) % 2;
    
    int next = num % twos;
    int next_twos = twos / 2;
    
    if(next == 0)
        return 1;
    
    if(num2>next_twos && next>=next_twos)
        return 0;
        
    if(num2 > next_twos)
        return find(next, num2-next_twos, next_twos);
    
    return find(next, num2, next_twos);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    int n, m;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        cin >> n >> m;
        
        cout << find(n-m, (m+1)/2, pow_2(m));
        cout << '\n';
    }
    
    // for(int i=1; i<63; i++) {
    //     for(int j=1; j<=i; j++) {
    //         cout << find(i-j, (j+1)/2, pow_2(j)) << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}