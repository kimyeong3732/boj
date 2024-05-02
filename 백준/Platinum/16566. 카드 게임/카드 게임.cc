#include <iostream>
#include <algorithm>

using namespace std;

int nums[4000000];
int parents[4000001];

int get_parent(int node) {
    if(parents[node] == node)
        return node;
    
    return parents[node] = get_parent(parents[node]);
}

void union_parent(int node) {
    int ap = get_parent(node);
    int bp = get_parent(ap+1);
    
    parents[ap] = bp;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    
    cin >> n >> m >> k;
    
    for(int i=0; i<m; i++) {
        int num;
        
        cin >> num;
        
        nums[i] = num;
        parents[i] = i;
    }
    parents[m] = m;
    
    sort(nums, nums+m);
    
    for(int i=0; i<k; i++) {
        int input_num;
        
        cin >> input_num;
        
        int pi = get_parent(upper_bound(nums, nums+m, input_num)-nums);
        
        cout << nums[pi] << '\n';
        
        union_parent(pi);
    }
    
    return 0;
}