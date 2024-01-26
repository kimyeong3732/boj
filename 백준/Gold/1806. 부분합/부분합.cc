#include <cstdio>
 
int main() {
	int n, s;
	int arr[100000];
 
	scanf("%d%d", &n, &s);
 
	arr[0] = 0;
	for(int i=1; i<=n; i++) {
		int temp;
		scanf("%d", &temp);
 
		temp += arr[i-1];
 
		arr[i] = temp;
	}
 
	if(arr[n] < s)
		printf("0\n" );
 
	else {
		int begin = 0, end = 0;
		int result = 100000;
 
		while(true) {
			if((arr[end]-arr[begin]) < s) {
				if(end == n) {
					break;
				}
				end++;
			}
			else {
				if(result > (end-begin)) {
					result = end - begin;
				}
				begin++;
			}
		}
		printf("%d\n", result);
	}
 
	return 0;
}