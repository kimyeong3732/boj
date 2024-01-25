#include <cstdio>
using namespace std;

int main() {
	int n, m;
	int arr[2000];
	bool dp[2000][2000];
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
		
	for(int i=n-1; i>=0; i--) {
		dp[i][i] = true;
		
		for(int j=i+1; j<n; j++) {
			if(j==i+1 || dp[i+1][j-1]) {
				dp[i][j] = arr[i] == arr[j];
			}
			else {
				dp[i][j] = false;
			}
		}
	}
	
	scanf("%d", &m);
	
	for(int i=0; i<m; i++) {
		int s, e, state = 1;
		scanf("%d%d", &s, &e);
		
		if(dp[s-1][e-1])
			printf("1\n");
		else
			printf("0\n");
	}
	
	return 0;
}