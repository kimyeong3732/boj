#include <iostream>

using namespace std;

int input[300000];
int l[300000], r[300000];
int result[300000];

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> input[i];
    
    l[0] = input[0];
    r[n-1] = input[n-1];
    
    for(int i=1; i<n; i++)
        l[i] = max(input[i], l[i-1]+input[i]);
    
    for(int i=n-2; i>=0; i--)
        r[i] = max(input[i], r[i+1]+input[i]);
    
    for(int i=0; i<n; i++)
        result[i] = l[i] + r[i] - input[i];
    
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    
    return 0;
}