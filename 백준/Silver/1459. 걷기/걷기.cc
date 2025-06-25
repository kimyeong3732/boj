#include <iostream>

using namespace std;

int main() {
    long long x, y, a, b;
    long long result = 0;
    
    cin >> x >> y >> a >> b;
    
    while(x>0 || y>0) {
        if(((x>0 && y>0) && (2*a)>b) || (((x>1 && y>=0) || (x>=0 && y>1)) && a>b))  {
            if(x>0 && y>0) {
                if(x > y) {
                    result += b * y;
                    x -= y;
                    y = 0;
                }
                else {
                    result += b * x;
                    y -= x;
                    x = 0;
                }
            }
            else if(x > 1) {
                result += 2 * b * (x / 2);
                x %= 2;
            }
            else if(y > 1) {
                result += 2 * b * (y / 2);
                y %= 2;
            }
        }
        else if(x > 0) {
            result += a * x;
            x = 0;
        }
        else if(y > 0) {
            result += a * y;
            y = 0;
        }
    }
    
    cout << result;
    
    return 0;
}