#include <iostream>

using namespace std;

int n;
int result, endnum;
bool status;
int parent[100001];
int lnum[100001];
int rnum[100001];

int findend(int s) {
    if(rnum[s] < 0)
        return s;
    
    return findend(rnum[s]);
}

void find(int s) {
    
    if(lnum[s] > 0) {
        result++;
        find(lnum[s]);
    }
    
    
    if(rnum[s] > 0) {
        result++;
        find(rnum[s]);
    }
    
    if(status)
        return;
    
    if(s == endnum) {
        status = true;
        return;
    }
    
    result++;
}

int main() {
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int num, l, r;
        
        cin >> num >> l >> r;
        
        lnum[num] = l;
        
        if(l > 0)
            parent[l] = num;
        
        rnum[num] = r;
        
        if(r > 0)
            parent[r] = num;
    }
    
    endnum = findend(1);
    
    find(1);
    
    cout << result;
    
    return 0;
}