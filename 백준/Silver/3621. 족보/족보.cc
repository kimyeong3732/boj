#include <iostream>

using namespace std;

int parents[100001];

int main() {
    int n, d;
    int result = 0;
    
    cin >> n >> d;
    
    for(int i=0; i<n; i++) {
        int temp;
        
        cin >> temp;
        
        if(parents[temp] == d) {
            parents[temp] = 1;
            result++;
        }
        
        parents[temp]++;
    }
    
    cout << result;
    
    return 0;
}