#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    int size = 0;
    int arr[1000001] = {0};

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(size==0)
            arr[size++] = temp;
        
        else {
        	int lb = lower_bound(arr, arr+size, temp) - arr;
        	
        	if(size == lb)
        		arr[size++] = temp;
        	else
        		arr[lb] = temp;
        }
    }
    
    cout << size << endl;

    return 0;
}