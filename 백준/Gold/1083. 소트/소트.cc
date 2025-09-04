#include <iostream>

using namespace std;

int nums[50];

void msort(int n, int s) {
    int c = 0;
    
    for(int i=0; i<n-1 && c<s; i++) {
        int mi = i;
        
        for(int j=i+1; j<=min(n-1, i+s-c); j++)
            if(nums[mi] < nums[j])
                mi = j;
        
        for(int j=mi; j>i; j--) {
            int temp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = temp;
            
            c++;
        }
    }
}

int main() {
    int n, s;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> nums[i];
    
    cin >> s;
    
    msort(n, s);
    
    for(int i=0; i<n; i++)
        cout << nums[i] << " ";
    
    return 0;
}