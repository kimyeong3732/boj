#include <iostream>

using namespace std;

int main() {
    int n;
    int nums[4] = {0, 0, 0, 0};
    string p;
    string t[50];
    
    cin >> p >> n;
    
    for(int i=0; i<p.size(); i++) {
        if(p[i] == 'L')
            nums[0]++;
        
        else if(p[i] == 'O')
            nums[1]++;
        
        else if(p[i] == 'V')
            nums[2]++;
        
        else if(p[i] == 'E')
            nums[3]++;
    }
    
    for(int i=0; i<n; i++)
        cin >> t[i];
    
    int max = -1;
    int result = 0;
    
    for(int i=0; i<n; i++) {
        int tnums[4];
        
        for(int j=0; j<4; j++)
            tnums[j] = nums[j];
        
        for(int j=0; j<t[i].size(); j++) {
            if(t[i][j] == 'L')
                tnums[0]++;
            
            else if(t[i][j] == 'O')
                tnums[1]++;
            
            else if(t[i][j] == 'V')
                tnums[2]++;
            
            else if(t[i][j] == 'E')
                tnums[3]++;
        }
        
        int num = ((tnums[0]+tnums[1]) * (tnums[0]+tnums[2]) * (tnums[0]+tnums[3]) * (tnums[1]+tnums[2]) * (tnums[1]+tnums[3]) * (tnums[2]+tnums[3])) % 100;
        
        
        if(max<num || (max==num && t[result]>t[i])) {
            result = i;
            max = num;
        }
    }
    
    cout << t[result];
    
    return 0;
}