#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;
int dp[10001][100];

int find(int d, int index) {
    if(index > n)
        return 0;
    
    if(d == 0)
        return dp[d][index] = 1;
    
    if(dp[d][index] != -1)
        return dp[d][index];
    
    int result = 0;
    
    for(int i=0; i<=v[index].second; i++) {
        int temp = v[index].first * i;
        
        if(d >= temp)
            result += find(d-temp, index+1);
    }
    
    return dp[d][index] = result;
}

int main() {
    int d;
    
    cin >> d >> n;
    
    for(int i=0; i<n; i++) {
        int a, b;
        
        cin >> a >> b;
        
        v.push_back(make_pair(a, b));
    }
    
    for(int i=0; i<=d; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = -1;
    
    cout << find(d, 0);
    
    return 0;
}