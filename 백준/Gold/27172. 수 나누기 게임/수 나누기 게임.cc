#include <iostream>

using namespace std;

int main() {
    int n;
    int input[100000];
    int score[1000001] = {0, };
    bool select[1000001] = {false, };
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        
        input[i] = temp;
        select[temp] = true;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=input[i]*2; j<=1000000; j+=input[i]) {
            if(select[j]) {
                score[input[i]]++;
                score[j]--;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << score[input[i]] << ' ';
    }
    
    return 0;
}