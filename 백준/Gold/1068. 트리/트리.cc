#include <iostream>
#include <vector>

using namespace std;

int d;
int result = 0;
vector<int> edges[50];

void dfs(int node) {
    bool state = false;
    
    for(int i=0; i<edges[node].size(); i++) {
        int next = edges[node][i];
        
        if(next != d)
            dfs(next);
        
        else
            state = true;
    }
    
    if(edges[node].empty() || (state && edges[node].size()==1))
        result++;
}

int main() {
    int n;
    int root;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num;
        
        cin >> num;
        
        if(num == -1)
            root = i;
        
        else
            edges[num].push_back(i);
    }
    
    cin >> d;
    
    edges[d].clear();
    
    if(root != d)
        dfs(root);
    
    cout << result;
    
    return 0;
}