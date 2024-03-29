#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    string cmd = "READ";
    cmd.reserve(10);
    stack<string> s;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string temp;
        temp.reserve(10);
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