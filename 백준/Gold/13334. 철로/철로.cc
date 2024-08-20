#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
    int x;
    int y;
    
    bool operator<(const point &o) const {
        if(x == o.x) {
            return y > o.y;
        }
        
        return x > o.x;
    }
};

bool cmp(const point &a, const point &b) {
    if(a.y == b.y) {
        return a.x < b.x;
    }
    
    return a.y < b.y;
}

int result = 0;

int main() {
    int n;
    vector<point> v;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        point p;
        
        cin >> a >> b;
        
        if(a > b) {
            p = {b, a};
        }
        else {
            p = {a, b};
        }
        
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    
    int d;
    int left = -100000000;
    int count = 0;
    priority_queue<point> pq;
    
    cin >> d;
    
    for(int i=0; i<v.size(); i++) {
        
        if(v[i].y - v[i].x > d) {
            continue;
        }
        
        pq.push(v[i]);
        count++;
        
        while(!pq.empty()) {
            if(pq.top().x+d >= v[i].y) {
                break;
            }
            pq.pop();
            count--;
        }
        
        if(count > result) {
            result = count;
        }
    }
    
    cout << result;
    
    return 0;
}