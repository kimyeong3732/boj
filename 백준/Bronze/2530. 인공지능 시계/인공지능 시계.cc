#include <iostream>

using namespace std;

int main() {
    int h, m, s;
    int num;
    
    cin >> h >> m >> s;
    cin >> num;
    
    s += num % 60;
    num /= 60;
    m += s / 60;
    s %= 60;
    
    m += num % 60;
    num /= 60;
    h += m / 60;
    m %= 60;
    
    h += num;
    h %= 24;
    
    cout << h << " " << m << " " << s;
    
    return 0;
}