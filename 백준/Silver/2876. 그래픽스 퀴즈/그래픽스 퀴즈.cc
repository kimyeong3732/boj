#include <iostream>

using namespace std;

int counts[100001][5];

int main() {
    int n;
    int max = 0;
    int result = 6;
    
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        counts[i][a-1] = counts[i-1][a-1] + 1;
        
        if(counts[i][a-1]>max || (counts[i][a-1]==max && a<result)) {
            max = counts[i][a-1];
            result = a;
        }
        
        if(a != b) {
            counts[i][b-1] = counts[i-1][b-1] + 1;
            if(counts[i][b-1]>max || (counts[i][b-1]==max && b<result)) {
                max = counts[i][b-1];
                result = b;
            }
        }
    }
    
    cout << max << " " << result;
    
    return 0;
}