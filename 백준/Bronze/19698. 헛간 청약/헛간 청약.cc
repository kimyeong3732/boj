#include <iostream>

using namespace std;

int main() {
    int n, w, h, l;
    
    cin >> n >> w >> h >> l;
    
    int max = (w / l) * (h / l);
    
    if(max < n)
        cout << max;
    else
        cout << n;
    
    return 0;
}