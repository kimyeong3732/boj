#include <iostream>

using namespace std;

int main() {
    int n;
    long long nums[50];
    long long cluster;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    cin >> cluster;
    
    long long size = 0;
    for(int i=0; i<n; i++) {
        size += nums[i] / cluster;
        
        if(nums[i]%cluster != 0)
            size++;
    }
    
    cout << cluster * size;
    
    return 0;
}