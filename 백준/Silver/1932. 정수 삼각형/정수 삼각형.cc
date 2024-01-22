#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> tri[500];
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int temp;
            
            scanf("%d", &temp);
            tri[i].push_back(temp);
        }
    }
    
    for(int i=n-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            int max = tri[i][j];
            
            if(max < tri[i][j+1])
                max = tri[i][j+1];
            
            tri[i-1][j] += max;
        }
    }
    
    printf("%d\n", tri[0][0]);
    
    return 0;
}