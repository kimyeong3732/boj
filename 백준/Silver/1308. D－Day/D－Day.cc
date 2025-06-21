#include <iostream>

using namespace std;

int main() {
    int nums[2] = {0, 0};
    int state = 0;
    int temp[3];
    
    for(int i=0; i<2; i++) {
        int y, m, d;
        
        cin >> y >> m >> d;
        
        if(i == 0) {
            temp[0] = y;
            temp[1] = m;
            temp[2] = d;
        }
        else {
            if(y-temp[0]>1000 || (y-temp[0]==1000 && (m>temp[1] || (m==temp[1] && d>=temp[2])))) {
                state = 1;
            }
        }
        
        nums[i] += (y - 1) * 365;
        nums[i] += (y - 1) / 4;
        nums[i] -= (y - 1) / 100;
        nums[i] += (y - 1) / 400;
        
        for(int j=1; j<m; j++) {
            switch(j) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                    nums[i] += 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    nums[i] += 30;
                    break;
                case 2:
                    nums[i] += 28;
                    if(y%400==0 || (y%100!=0 && y%4==0))
                        nums[i] += 1;
                    break;
                default:
                    break;
            }
        }
        
        nums[i] += d;
    }
    
    if(state == 1)
        cout << "gg";
    else
        cout << "D-" << nums[1] - nums[0];
    
    return 0;
}