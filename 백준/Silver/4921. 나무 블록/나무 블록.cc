#include <iostream>

using namespace std;

int main() {
    string num;
    int t = 1;
    
    cin >> num;
    
    while(num.compare("0")) {
        int status = 0;
        
        for(int i=num.size()-1; i>=0; i--) {
            int one = num[i] - '0';
            
            switch(status) {
                case 0:
                    if(one != 2)
                        status = -1;
                    break;
                case 2:
                case 3:
                    if(one!=4 && one!=6)
                        status = -1;
                    break;
                case 4:
                case 5:
                    if(one!=1 && one!=3)
                        status = -1;
                    break;
                case 6:
                case 7:
                    if(one != 8)
                        status = -1;
                    break;
                case 8:
                    if(one!=5 && one!=7)
                        status = -1;
                    break;
                default:
                    if(i > 0)
                        status = -1;
            }
            
            if(status < 0) {
                cout << t << ". NOT\n";
                break;
            }
            
            status = one;
        }
        
        if(status == 1)
            cout << t << ". VALID\n";
        else if(status > 0)
            cout << t << ". NOT\n";
        
        t++;
        cin >> num;
    }
    
    return 0;
}