#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n;
        
        cin >> n;
        
        string num, s;
        
        cin >> num >> s;
        
        int nums[100];
        
        for(int j=0; j<n; j++)
            nums[j] = num[j] - '0';
        
        int result = 0;
        
        for(int j=0; j<n; j++) {
            if(j==0 && nums[j]>0 && nums[j+1]>0) {
                nums[j]--;
                nums[j+1]--;
                result++;
            }
            
            else if(j==n-1 && nums[j-1]>0 && nums[j]>0) {
                nums[j-1]--;
                nums[j]--;
                result++;
            }
            
            else if(nums[j-1]>0 && nums[j]>0 && nums[j+1]>0) {
                nums[j-1]--;
                nums[j]--;
                nums[j+1]--;
                result++;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}