#include <iostream>

using namespace std;

int parents[500000];

int get_parent(int num) {
    if(num == parents[num])
        return num;
    
    return parents[num] = get_parent(parents[num]);
}

void my_union(int ap, int bp) {
    parents[ap] = bp;
}

int main() {
    int n, m;
    int result = 0;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        parents[i] = i;
        
    for(int i=1; i<=m; i++) {
        int a, b;
        
        cin >> a >> b;
        
        int ap = get_parent(a);
        int bp = get_parent(b);
        
        if(ap != bp)
            my_union(ap, bp);
        else if(result == 0)
            result = i;
    }
    
    cout << result;
    
    return 0;
}