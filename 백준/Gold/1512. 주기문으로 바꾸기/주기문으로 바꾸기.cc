#include <iostream>

using namespace std;

int main() {
    int m;
    int result = 3000;
    string s;
    
    cin >> m >> s;
    
    while(m > 0) {
        int temp = 0;
        
        for(int i=0; i<m; i++) {
            int num[4] = {0};
            int index = i;
            
            while(index < s.size()) {
                switch(s[index]) {
                case 'A':
                    num[0]++;
                    break;
                case 'C':
                    num[1]++;
                    break;
                case 'G':
                    num[2]++;
                    break;
                case 'T':
                    num[3]++;
                    break;
                default:
                    break;
                }
                
                index += m;
            }
            
            int mm = 0;
            int sum = 0;
            for(int j=0; j<4; j++) {
                sum += num[j];
                mm = max(mm, num[j]);
            }
            
            temp += sum - mm;
        }
        
        result = min(result, temp);
        
        m--;
    }
    
    cout << result;
    
    return 0;
}