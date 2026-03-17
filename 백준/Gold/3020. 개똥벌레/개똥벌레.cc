#include <iostream>

using namespace std;

int top[500001];
int bottom[500001];

int main() {
    int n, h;
    
    cin >> n >> h;
    
    for(int i=0; i<n; i++) {
        int input;
        
        cin >> input;
        
        if(i%2 == 0)
            bottom[input]++;
        
        else
            top[h-input+1]++;
    }
    
    for(int i=h; i>0; i--)
        bottom[i-1] += bottom[i];
    
    for(int i=1; i<=h; i++)
        top[i] += top[i-1];
    
    int result = n + 1;
    int count = 0;
    
    for(int i=1; i<=h; i++) {
        if(top[i]+bottom[i] < result) {
            result = top[i] + bottom[i];
            count = 1;
        }
        
        else if(top[i]+bottom[i] == result)
            count++;
    }
    
    cout << result << " " << count;
    
    return 0;
}