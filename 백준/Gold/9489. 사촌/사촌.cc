#include <iostream>

using namespace std;

int main() {
    int n, d;
    
    cin >> n >> d;
    
    while(n+d > 0) {
        int di;
        int arr[1000];
        int p[1000], depth[1000];
        
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            
            if(d == arr[i])
                di = i;
        }
        
        p[0] = -1;
        depth[0] = 0;
        
        int c = -1;
        
        for(int i=1; i<n; i++) {
            if(arr[i-1]+1 < arr[i])
                c++;
            
            p[i] = c;
            depth[i] = depth[c] + 1;
        }
        
        int result = 0;
        
        for(int i=0; i<n; i++) {
            if(depth[i] < depth[di])
                continue;
            
            if(depth[i] > depth[di])
                break;
            
            if(p[i]!=p[di] && p[p[i]]==p[p[di]])
                result++;
        }
        
        cout << result << "\n";
        
        cin >> n >> d;
    }
    
    return 0;
}