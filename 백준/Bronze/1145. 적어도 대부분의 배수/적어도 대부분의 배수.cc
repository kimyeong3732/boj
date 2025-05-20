#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int nums[5];
    int result = -1;
    
    for(int i=0; i<5; i++)
        cin >> nums[i];
    
    for(int i=0; i<3; i++) {
        for(int j=i+1; j<4; j++) {
            int temp = lcm(nums[i], nums[j]);
            
            for(int k=j+1; k<5; k++) {
                int temp2 = lcm(temp, nums[k]);
                
                if(temp2<result || result<0) {
                    result = temp2;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}