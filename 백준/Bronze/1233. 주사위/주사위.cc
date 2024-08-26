#include <iostream>

using namespace std;

int score[81];
int result = 0;

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int k=1; k<=c; k++) {
                int num = i + j + k;
                score[num] += 1;
                
                if(score[result] < score[num]) {
                    result = num;
                }
                else if(score[result]==score[num] && result>num) {
                    result = num;
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}