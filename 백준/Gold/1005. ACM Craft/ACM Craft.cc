#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    for(int i=0; i<t; i++) {
        int n, k;
        int cost[1001];
        int ncount[1001];
        int dp[1001];
        
        cin >> n >> k;
        
        for(int j=1; j<=n; j++) {
            cin >> cost[j];
            ncount[j] = 0;
            dp[j] = 0;
        }
        
        vector<int> edges[1001];
        
        for(int j=0; j<k; j++) {
            int a, b;
            
            cin >> a >> b;
            
            edges[a].push_back(b);
            ncount[b]++;
        }
        
        int rd;
        
        cin >> rd;
        
        queue<int> topo;
        
        while(topo.size() < n) {
            for(int j=1; j<=n; j++) {
                if(ncount[j] == 0) {
                    topo.push(j);
                    ncount[j]--;
                
                    for(int k=0; k<edges[j].size(); k++)
                        ncount[edges[j][k]]--;
                }
            }
        }
        
        while(!topo.empty()) {
            int num = topo.front();
            topo.pop();
            
            dp[num] += cost[num];
            
            for(int j=0; j<edges[num].size(); j++)
                dp[edges[num][j]] = max(dp[edges[num][j]], dp[num]);
        }
        
        cout << dp[rd] << "\n";
    }
    
    return 0;
}