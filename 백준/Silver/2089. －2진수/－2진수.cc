#include <iostream>

using namespace std;

int main()
{
    int num;
    string result = "";
    
    cin >> num;
    
    if(num == 0)
        result = "0";
    
    while(num != 0) {
        int temp = num % -2;
        num /= -2;
        
        if(temp < 0) {
            num++;
            temp = 1;
        }
        
        result = (char)(temp + '0') + result;
    }
    
    cout << result;

    return 0;
}