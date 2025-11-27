#include <iostream>

using namespace std;

int find(int x, int y) {
    int n = max(abs(x), abs(y));
    
    int mnum = n * 2 + 1;
    mnum *= mnum;
    
    if(y == n)
        return mnum + x - n;
    
    mnum -= 2 * n;
    
    if(x == -n)
        return mnum + y - n;
    
    mnum -= 2 * n;
    
    if(y == - n)
        return mnum - x - n;
    
    mnum -= 2 * n;
    
    return mnum - y - n;
}

int main() {
    int x1, x2, y1, y2;
    
    cin >> y1 >> x1 >> y2 >> x2;
    
    int digit = 1;
    
    for(int i=y1; i<=y2; i++) {
        for(int j=x1; j<=x2; j++) {
            int num = find(j, i);
            
            int temp = 0;
            
            while(num > 0) {
                temp++;
                num /= 10;
            }
            
            if(digit < temp)
                digit = temp;
        }
    }
    
    for(int i=y1; i<=y2; i++) {
        for(int j=x1; j<=x2; j++) {
            int num = find(j, i);
            
            int temp = 0;
            int tnum = num;
            
            while(tnum > 0) {
                temp++;
                tnum /= 10;
            }
            
            if(temp == 0)
                temp = 1;
            
            for(int k=temp; k<digit; k++)
                cout << " ";
            
            cout << num << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}