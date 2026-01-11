#include <iostream>

using namespace std;

int arr[50000];

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
	
    int n;
    int sum = 0;
    int result = 0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    int e = 0;
    int dist = 0;
    
    for(int i=0; i<n; i++) {
        while(true) {
            dist += arr[e];
            
            if(dist > sum/2) {
                dist -= arr[e];
                break;
            }
            
            e = (e + 1) % n;
        }
        
        result = max(result, dist);
        
        dist -= arr[i];
    }
    
    cout << result;
    
    return 0;
}