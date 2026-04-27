#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int dp[1000][16][16];

int find(int index, int bn, int wn) {
    if(index == v.size())
        return 0;
    
    if(bn==15 && wn==15)
        return 0;
    
    if(dp[index][bn][wn] >= 0)
        return dp[index][bn][wn];
    
    dp[index][bn][wn] = max(dp[index][bn][wn], find(index+1,bn,wn));
    
    if(bn < 15)
        dp[index][bn][wn] = max(dp[index][bn][wn], find(index+1,bn+1,wn)+v[index].first);
    
    if(wn < 15)
        dp[index][bn][wn] = max(dp[index][bn][wn], find(index+1,bn,wn+1)+v[index].second);
    
    return dp[index][bn][wn];
}

int main() {
    int a, b;
    
    while(scanf("%d %d", &a, &b) == 2)
        v.push_back(make_pair(a, b));
    
    for(int i=0; i<v.size(); i++)
        for(int j=0; j<=15; j++)
            for(int k=0; k<=15; k++)
                dp[i][j][k] = -1;
    
    cout << find(0, 0, 0);
    
    return 0;
}