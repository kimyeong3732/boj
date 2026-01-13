#include <iostream>

using namespace std;

int nums[5001];
int dp[5001];

int main() {
    string s;
    
    cin >> s;
    
    for(int i=1; i<=s.size(); i++)
        nums[i] = s[i-1] - '0';
    
    if(nums[1] == 0) {
        cout << 0;
    }
    
    else {
        dp[0] = 1;
        
        for(int i=1; i<=s.size(); i++) {
            if(nums[i] > 0)
                dp[i] = (dp[i-1] + dp[i]) % 1000000;
            
            if(i == 1)
                continue;
            
            int temp = nums[i-1]*10 + nums[i];
            
            if(temp>9 && temp<=26)
                dp[i] = (dp[i-2] + dp[i]) % 1000000;
        }
        
        cout << dp[s.size()];
    }
    
    return 0;
}