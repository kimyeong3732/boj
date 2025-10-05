#include <iostream>

using namespace std;

int main() {
    int n;
    int result = 0;
    int mr = -1;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int nums[5];
        
        for(int j=0; j<5; j++)
            cin >> nums[j];
        
        int mt = -1;
        
        for(int j=0; j<3; j++) {
            int t = nums[j];
            
            for(int k=j+1; k<4; k++) {
                t += nums[k];
                
                for(int l=k+1; l<5; l++) {
                    t += nums[l];
                    
                    if(mt < (t%10))
                        mt = t % 10;
                    
                    t -= nums[l];
                }
                
                t -= nums[k];
            }
        }
        
        if(mr <= mt) {
            mr = mt;
            
            result = i + 1;
        }
    }
    
    cout << result;
    
    return 0;
}