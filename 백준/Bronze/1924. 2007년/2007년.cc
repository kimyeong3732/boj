#include <iostream>

using namespace std;

int main() {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    int mon, day;
    
    cin >> mon >> day;
    
    for(int i=0; i<mon; i++) {
        day += days[i];
    }
    
    cout << week[day%7];
    
    return 0;
}