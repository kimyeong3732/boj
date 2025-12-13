#include <iostream>

using namespace std;

long long nums[10];
bool fn[10];

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string s;
        
        cin >> s;
        
        long long digit = 1;
        
        for(int j=s.size()-1; j>=0; j--) {
            nums[s[j]-'A'] += digit;
            digit *= 10;
        }
        
        fn[s[0]-'A'] = true;
    }
    
    long long minn = 6000000000000;
    int minid = -1;
    for(int i=0; i<10; i++) {
        if(!fn[i] && minn>nums[i]) {
            minn = nums[i];
            minid = i;
        }
    }
    
    nums[minid] = 0;
    
    long long result = 0;
    
    for(int i=9; i>0; i--) {
        long long maxn = -1;
        int maxid = -1;
        
        for(int j=0; j<10; j++) {
            if(maxn < nums[j]) {
                maxn = nums[j];
                maxid = j;
            }
        }
        
        result += i * maxn;
        nums[maxid] = 0;
    }
    
    cout << result;
    
    return 0;
}