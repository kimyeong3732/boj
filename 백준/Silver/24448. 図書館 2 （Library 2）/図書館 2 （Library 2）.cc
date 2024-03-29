#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    int n;
    string cmd = "READ";
    stack<string> s;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        
        if(temp == cmd) {
            if(!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else {
            s.push(temp);
        }
    }
    
    return 0;
}