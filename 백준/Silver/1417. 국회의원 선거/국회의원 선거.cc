#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, vote;
    int result = 0;
    priority_queue<int> pq;
    
    cin >> n >> vote;
    
    for(int i=0; i<n-1; i++) {
        int temp;
        
        cin >> temp;
        
        pq.push(temp);
    }
    
    while(!pq.empty() && vote <= pq.top()) {
        int temp = pq.top();
        pq.pop();
        
        vote++;
        pq.push(temp-1);
        result++;
    }
    
    cout << result;
    
    return 0;
}