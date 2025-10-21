#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> v;
    priority_queue<int> pq;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int d, num;
        
        cin >> d >> num;
        
        v.push(make_pair(d, num));
    }
    
    int dd, rest;
    int r = 0;
    
    cin >> dd >> rest;
    
    while(dd > rest) {
        while(!v.empty() && v.top().first<=rest) {
            pq.push(v.top().second);
            
            v.pop();
        }
        
        if(pq.empty())
            break;
        
        rest += pq.top();
        r++;
        pq.pop();
    }
    
    if(dd > rest)
        cout << -1;
    
    else
        cout << r;
    
    return 0;
}