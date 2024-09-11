#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int arr[50];
    int num;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> num;
    sort(arr, arr+n);
    
    int i=0;
    while(arr[i] < num) {
        i++;
    }
    
    int result = 0;
    
    if(arr[i] == num) {
        cout << result;
        return 0;
    }
    
    for(int j=i!=0?arr[i-1]+1:1; j<arr[i]; j++) {
        for(int k=j+1; k<arr[i]; k++) {
            if(j>num || k<num) {
                continue;
            }
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}