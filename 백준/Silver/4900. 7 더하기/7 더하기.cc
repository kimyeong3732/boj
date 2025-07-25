#include <iostream>

using namespace std;

int main() {
    string s;
    string nums[10] = {"063", "010", "093", "079", "106", "103", "119", "011", "127", "107"};
    
    cin >> s;
    
    while(s != "BYE") {
        int num1=0, num2=0;
        
        int j = 0;
        string temp = "";
        
        for(int i=j; s[i]!='+'; i++) {
            temp += s[i];
            
            if(j+2 == i) {
                num1 *= 10;
                
                for(int k=0; k<10; k++) {
                    if(nums[k] == temp) {
                        num1 += k;
                        break;
                    }
                }
                
                temp = "";
                j = i + 1;
            }
        }
        
        j++;
        
        for(int i=j; s[i]!='='; i++) {
            temp += s[i];
            
            if(j+2 == i) {
                num2 *= 10;
                
                for(int k=0; k<10; k++) {
                    if(nums[k] == temp) {
                        num2 += k;
                        break;
                    }
                }
                
                temp = "";
                j = i + 1;
            }
        }
        
        int result = num1 + num2;
        string rt[10];
        j = 0;
        
        while(result > 0) {
            rt[j] = nums[result%10];
            j++;
            result /= 10;
        }
        
        cout << s;
        for(int i=j-1; i>=0; i--)
            cout << rt[i];
        
        cout << "\n";
        
        cin >> s;
    }
    
    return 0;
}