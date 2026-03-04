#include <iostream>

using namespace std;

int arr[1000000];
int ud[1000000];

int main() {
    int n;
    int nu=0, nd=0;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++) {
        if(arr[i] < arr[(i+1)%n]) {
            ud[i] = 1;
            nu++;
        }
        
        else if(arr[i] > arr[(i+1)%n]) {
            ud[i] = -1;
            nd++;
        }
    }
    
    if(nu>1 && nd>1) {
        cout << -1;
    }
    
    else {
        if(nu+nd == 0) {
            cout << 0;
        }
        
        else if(nu == nd) {
            bool state = false;
            int result = n;
            
            for(int i=0; i<n; i++)
                if(ud[i] != 0)
                    result = min(result, (i+1)%n);
            
            cout << result;
        }
        
        else {
            int check;
            
            if(nu == 1)
                check = 1;
            
            else
                check = -1;
            
            for(int i=0; i<n; i++) {
                if(ud[i] == check) {
                    cout << (i+1)%n;
                    
                    break;
                }
            }
        }
    }
    
    return 0;
}