#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    int result = 0;
    stack<int> s;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int x, y;
        
        cin >> x >> y;
        
        while(!s.empty() && s.top()>=y) {
            if(s.top() > y)
                result++;
            
            s.pop();
        }
        
        if(y != 0)
            s.push(y);
    }
    
    while(!s.empty()) {
        result++;
        s.pop();
    }
    
    cout << result;
    
    return 0;
}