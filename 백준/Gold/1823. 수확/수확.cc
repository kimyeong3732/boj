#include <iostream>

using namespace std;

int input[2001];
int dp[2001][2001];

int find(int s, int e, int count) {
    if(s > e)
        return 0;
    
    if(dp[s][e] > 0)
        return dp[s][e];
    
    int result = max(find(s+1, e, count+1)+input[s]*count, find(s, e-1, count+1)+input[e]*count);
    
    return dp[s][e] = result;
}

int main() {
    int n;
    
    cin >> n;
    
    for(int i=1; i<=n; i++)
        cin >> input[i];
    
    
    cout << find(1, n, 1);
    
    return 0;
}