#include <iostream>
using namespace std;

int main() {
    int k, n, num;
    long long min = 1, max, result = 0;
    int arr[10000];
    
    cin >> k >> n;
    
    for(int i=0; i<k; i++) {
        cin >> arr[i];
        result += arr[i];
    }
    
    max = result / n;
    
    while(min <= max) {
        num = 0;
         result = (min+max) / 2;
        for(int i=0; i<k; i++)
            num += arr[i] / result;
        
        if(num >= n) min = result + 1;
        else max = result - 1;
    }
    
    if(num < n) result--;
    
    cout << result << endl;
    
    return 0;
}