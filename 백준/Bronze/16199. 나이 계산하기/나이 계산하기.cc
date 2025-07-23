#include <iostream>

using namespace std;

int main() {
    int y1, y2, m1, m2, d1, d2;
    
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    
    int result = y2 - y1;
    
    if(y2>y1 && (m2<m1 || (m2==m1 && d2<d1)))
        cout << result - 1 << "\n";
    
    else
        cout << result << "\n";
    
    cout << result + 1 << "\n";
    
    cout << result;
    
    return 0;
}