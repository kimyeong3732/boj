#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[50];
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    if(n < 3) {
        cout << n;
    }
    
    else {
        int result = 0;
        
        for(int i=0; i<n-2; i++) {
            int c = 2;
            
            for(int j=i+2; j<n; j++) {
                if(arr[i]+arr[i+1] > arr[j])
                    c++;
                
                else
                    break;
            }
            
            result = max(result, c);
        }
        
        cout << result;
    }
    
    return 0;
}