#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v[1000001];
bool visit[1000001];
int dp[1000001][2];

void find(int node) {
    visit[node] = true;
    bool state = false;
    
    for(int i=0; i<v[node].size(); i++) {
        int next = v[node][i];
        
        if(visit[next]) {
            continue;
        }
        
        find(next);
        
        dp[node][0] += dp[next][1];
        
        if(min(dp[next][0], dp[next][1]) == 0) {
            state = true;
        }
        dp[node][1] += min(dp[next][0], dp[next][1]);
    }
    
    dp[node][1] += 1;
}

int main() {
    cin >> n;
    
    for(int i=0; i<n-1; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    find(1);
    
    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}