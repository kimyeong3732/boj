#include <iostream>
#include <utility>
#include <deque>

using namespace std;

int main() {
    int n;
    deque<pair<int, int>> dq;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        int num;
        
        cin >> num;
        
        dq.push_back(make_pair(i, num));
    }
    
    for(int i=0; i<n; i++) {
        int num = dq.front().second;
        
        cout <<dq.front().first << " ";
        
        dq.pop_front();
        
        if(num < 0) {
            for(int j=0; j<-1*num; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else {
            for(int j=0; j<num-1; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
    
    return 0;
}