#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    int nums[9][9];
    int result = -1;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++) {
        string temp;
        
        cin >> temp;
        
        
        for(int j=0; j<m; j++) {
            nums[i][j] = temp[j] - '0';
            
            if(result<nums[i][j] && (nums[i][j]==0 || nums[i][j]==1 || nums[i][j]==4 || nums[i][j]==9))
                result = nums[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int dy=-i; dy<n-i; dy++) {
                for(int dx=-j;dx<m-j; dx++) {
                    if(dx==0 && dy==0)
                        continue;
                    
                    int nx = j;
                    int ny = i;
                    int num = nums[i][j];
                    
                    while(true) {
                        nx += dx;
                        ny += dy;
                        
                        if(nx<0 || nx>=m || ny<0 || ny>=n)
                            break;
                        
                        num *= 10;
                        num += nums[ny][nx];
                        
                        int c = sqrt(num);
                        
                        if(result<num && c*c==num)
                            result = num;
                    }
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}