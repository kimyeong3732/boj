#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string num;
    int result = 0;
    
    cin >> num;
    
    for(int i=0; i<num.size(); i++) {
        result *= 16;
        
        if(num[i]>='0' && num[i]<='9')
            result += num[i] - '0';
        else
            result += num[i] - 'A' + 10;
    }
    
    cout << result;
    
    return 0;
}