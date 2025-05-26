#include <iostream>

using namespace std;

int main() {
    string cmd;
    int result = 0;
    
    cin >> cmd;
    
    for(int i=0; i<cmd.size(); i++)
        if(cmd[i]>='A' && cmd[i]<='Z')
            if((i+result)%4 != 0)
                result += ((i+result)/4+1)*4 - (i+result);
    
    cout << result;
    
    return 0;
}