#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        pq.push(num);
    }
    
    int result = 0;
    
    while(pq.size() > 1) {
        int temp = pq.top();
        
        pq.pop();
        
        temp += pq.top();
        
        pq.pop();
        
        result += temp;
        
        pq.push(temp);
    }
    
    cout << result;
    
    return 0;
}