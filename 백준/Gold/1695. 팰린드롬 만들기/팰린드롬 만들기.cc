#include <iostream>

using namespace std;

int nums[5000];
int dp[5000][5000];

int find(int s, int e) {
    if(s >= e)
        return 0;
    
    if(dp[s][e] >= 0)
        return dp[s][e];
    
    int c = 0;
    
    if(nums[s] == nums[e])
        c = find(s+1, e-1);
    
    else
        c = min(find(s+1,e)+1, find(s,e-1)+1);
    
    return dp[s][e] = c;
}

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = -1;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    cout << find(0, n-1);
    
    return 0;
}