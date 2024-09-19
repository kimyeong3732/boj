#include <iostream>

using namespace std;

long long arr[1000001];
long long seg_tree[4000001];
int target, lnum, rnum;
long long diff;

long long init(int node, int start, int end) {
    if(start == end) {
        return seg_tree[node] = arr[start];
    }
    int middle = (start + end) / 2;
    
    return seg_tree[node] = init(node*2, start, middle) + init(node*2+1, middle+1, end);
}

void update(int node, int start, int end) {
    if(start>target || end<target) {
        return;
    }
    
    seg_tree[node] += diff;
    if(start==end) {
        return;
    }
    
    int middle = (start + end) / 2;
    
    update(node*2, start, middle);
    update(node*2+1, middle+1, end);
}

long long get(int node, int start, int end) {
    if(rnum<start || end<lnum) {
        return 0;
    }
    
    if(lnum<=start && end<=rnum) {
        return seg_tree[node];
    }
    
    int middle = (start + end) / 2;
    
    return get(node*2, start, middle) + get(node*2+1, middle+1, end);
}

int main() {
    int n, m, k;
    
    cin >> n >> m >> k;
    
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    
    init(1, 1, n);
    
    for(int i=0; i<m+k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
            target = b;
            diff = c - arr[b];
            arr[b] = c;
            
            update(1, 1, n);
        }
        else {
            lnum = b;
            rnum = c;
            
            cout << get(1, 1, n) << "\n";
        }
    }
    
    return 0;
}