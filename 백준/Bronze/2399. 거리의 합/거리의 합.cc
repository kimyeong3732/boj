#include <iostream>

using namespace std;

int main() {
    int n;
    long long num[10000];
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> num[i];
    
    long long result = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j) {
                int dis = num[j] - num[i];
                
                if(dis < 0)
                    dis *= -1;
                
                result += dis;
            }
        }
    }
    
    cout << result;
    
    return 0;
}