#include <iostream>
#include <set>

using namespace std;

int n;
int edge[101];
bool visit[101];
set<int> result;

void dfs(int s) {
    for(int i=1; i<=n; i++)
        visit[i] = false;
    
    int j = s;
    
    while(!visit[j]) {
        visit[j] = true;
        
        j = edge[j];
    }
    
    if(s == j)
        result.insert(s);
}

int main() {
    cin >> n;
    
    for(int i=1; i<=n; i++)
        cin >> edge[i];
    
    for(int i=1; i<=n; i++)
        dfs(i);
    
    cout << result.size() << "\n";
    
    for(set<int>::iterator i=result.begin(); i!=result.end(); i++)
        cout << *i << "\n";
    
    return 0;
}