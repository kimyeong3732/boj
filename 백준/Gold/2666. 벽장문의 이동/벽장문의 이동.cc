#include <iostream>

using namespace std;

int n;
int m;
int arr[20];
int dp[20][21][21];

int find(int t, int a, int b) {
    if(t == m)
        return 0;
    
    if(dp[t][a][b] != -1)
        return dp[t][a][b];
    
    if(arr[t] <= a)
        return dp[t][a][b] = find(t+1, arr[t], b) + a - arr[t];
    
    else if(a<arr[t] && arr[t]<b)
        return dp[t][a][b] = min(find(t+1,arr[t],b)+arr[t]-a, find(t+1,a,arr[t])+b-arr[t]);
    
    else
        return dp[t][a][b] = find(t+1, a, arr[t]) + arr[t] - b;
}

int main() {
    int a, b;
    
    cin >> n;
    cin >> a >> b;
    cin >> m;
    
    for(int i=0; i<m; i++)
        cin >> arr[i];
    
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<m; k++)
                dp[k][j][i] = -1;
    
    cout << find(0, a, b);
    
    return 0;
}