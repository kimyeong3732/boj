#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int num, int s, int m, int e) {
    if(num == 0)
        return;
    
    hanoi(num-1, s, e, m);
    
    cout << s << " " << e << "\n";
    
    hanoi(num-1, m, s, e);
}

int main() {
    int n;
    
    cin >> n;
    
    string result = to_string(pow(2, n));
    
    int point = result.find('.');
    result = result.substr(0, point);
    result[result.size()-1]--;
    
    cout << result << "\n";
    
    if(n <= 20)
        hanoi(n, 1, 2, 3);
    
    return 0;
}