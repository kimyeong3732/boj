#include<iostream>

using namespace std;

int main() {
    int n;
    int result_max = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int nums[7] = {0, 0, 0, 0, 0, 0};
        int target = 0;
        
        for(int j=0; j<3; j++) {
            int num;
            
            cin >> num;
            
            nums[num]++;
            
            if(nums[target] < nums[num]) {
                target = num;
            }
            else if(nums[target]==nums[num] && target<num){
                target = num;
            }
        }
        
        int result = 0;
        
        if(nums[target] == 3) {
            result = 10000 + target * 1000;
        }
        else if(nums[target] == 2) {
            result = 1000 + target * 100;
        }
        else {
            result = target * 100;
        }
        
        if(result_max < result) {
            result_max = result;
        }
    }
    
    cout << result_max;
    
    return 0;
}