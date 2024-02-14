#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int size = 0;
    int src[1000000];
    int arr[1000001];
    int position[1000000];
    int result[1000000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", src+i);
        if(size==0) {
            position[i] = size;
            arr[size++] = src[i];
        }
        
        else {
        	int lb = lower_bound(arr, arr+size, src[i]) - arr;
        	
        	if(size == lb) {
        	    position[i] = size;
        		arr[size++] = src[i];
        	}
        	else {
        	    position[i] = lb;
        		arr[lb] = src[i];
        	}
        }
    }
    
    int find_size = size - 1;
    int index = n - 1;
    
    while(find_size >= 0) {
        if(position[index] == find_size)
            result[find_size--] = src[index];
            
        index--;
    }
    
    printf("%d\n", size);
    
    for(int i=0; i<size; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}