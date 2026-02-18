#include <iostream>

using namespace std;

int index = -1;
long long st[30];

int main() {
    string s;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(' || s[i]=='[') {
            index++;
            
            if(s[i] == '(')
                st[index] = -1;
            
            else
                st[index] = -2;
        }
        
        else {
            if(s[i] == ')') {
                long long temp = 0;
                
                while(index>=0 && st[index]>0) {
                    temp += st[index];
                    index--;
                }
                
                if(index<0 || st[index]==-2) {
                    index = -1;
                    break;
                }
                
                if(temp == 0)
                    temp = 1;
                
                st[index] = temp * 2;
            }
            
            else {
                long long temp = 0;
                
                while(index>=0 && st[index]>0) {
                    temp += st[index];
                    index--;
                }
                
                if(index<0 || st[index]==-1) {
                    index = -1;
                    break;
                }
                
                if(temp == 0)
                    temp = 1;
                
                st[index] = temp * 3;
            }
        }
    }
    
    long long result = 0;
    
    for(int i=0; i<=index; i++) {
        if(st[i] < 0) {
            result = 0;
            break;
        }
        
        result += st[i];
    }
    
    cout << result;
    
    return 0;
}