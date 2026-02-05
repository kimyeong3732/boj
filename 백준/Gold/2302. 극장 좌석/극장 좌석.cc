#include <iostream>

using namespace std;

int dp[41];

int find(int num) {
  if(dp[num] != 0)
      return dp[num];

  return dp[num] = find(num-1) + find(num-2);
}

int main() {
  int n, m;
  int result = 1;
  
  dp[0] = 1;
  dp[1] = 1;
  
  cin >> n >> m;
  
  int c = 1;
  
  for(int i=0; i<m; i++) {
    int num;

    cin >> num;

    result *= find(num-c);

    c = num + 1;
  }

  result *= find(n-c+1);

  cout << result;
  
  return 0;
}