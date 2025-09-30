#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<int> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        if(num == 0) {
            if(pq.size() == 0) {
                cout << -1;
            }
            
            else {
                cout << pq.top();
                pq.pop();
            }
            
            cout << "\n";
        }
        
        else {
            for(int j=0; j<num; j++) {
                int temp;
                
                cin >> temp;
                
                pq.push(temp);
            }
        }
    }
    
    return 0;
}