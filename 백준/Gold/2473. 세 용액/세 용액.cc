#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int arr[5000];
long long minnum = 3000000001;
int result[3];

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for(int i=0; i<n-2; i++) {
        int begin = i + 1;
        int end = n - 1;
        
        while(begin < end) {
            long long temp = (long long) arr[i] + arr[begin] + arr[end];
            
            if(minnum > abs(temp)) {
                minnum = abs(temp);
                result[0] = arr[i];
                result[1] = arr[begin];
                result[2] = arr[end];
            }
            
            if(temp < 0) {
                begin++;
            }
            else {
                end--;
            }
            
        }
    }
    
    for(int i=0; i<3; i++) {
        cout << result[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}