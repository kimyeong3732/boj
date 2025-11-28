#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ncount[501];
int result[501];

int main() {
    int n;
    int input[501];
    vector<int> edges[501];
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        int num;
        
        cin >> num;
        
        input[i] = num;
        
        cin >> num;
        
        while(num != -1) {
            edges[num].push_back(i);
            ncount[i]++;
            
            cin >> num;
        }
    }
    
    queue<int> topo;
    
    while(topo.size() < n) {
        for(int i=1; i<=n; i++) {
            if(ncount[i] == 0) {
                topo.push(i);
                ncount[i]--;
                
                for(int j=0; j<edges[i].size(); j++)
                    ncount[edges[i][j]]--;
            }
        }
    }
    
    while(!topo.empty()) {
        int num = topo.front();
        topo.pop();
        
        result[num] += input[num];
        
        for(int i=0; i<edges[num].size(); i++)
            result[edges[num][i]] = max(result[edges[num][i]], result[num]);
    }
    
    
    for(int i=1; i<=n; i++)
        cout << result[i] << "\n";
    
    return 0;
}