#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int s, b;
        priority_queue<int, vector<int>, greater<int>> spq;
        priority_queue<int, vector<int>, greater<int>> bpq;
        
        cin >> s >> b;
        
        for(int j=0; j<s; j++) {
            int temp;
            
            cin >> temp;
            
            spq.push(temp);
        }
        
        for(int j=0; j<b; j++) {
            int temp;
            
            cin >> temp;
            
            bpq.push(temp);
        }
        
        while(!spq.empty() && !bpq.empty()) {
            if(spq.top() >= bpq.top())
                bpq.pop();
            
            else
                spq.pop();
        }
        
        if(spq.empty())
            cout << "B\n";
        
        else
            cout << "S\n";
    }
    
    return 0;
}