#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int a1, b1, r1, a2, b2, r2;
        
        cin >> a1 >> b1 >> r1 >> a2 >> b2 >> r2;
        
        int dis = (a2-a1)*(a2-a1) + (b2-b1)*(b2-b1);
        int max_dis = (r1+r2) * (r1+r2);
        int min_dis = (r1-r2) * (r1-r2);
        
        if(dis==0 && r1==r2) {
            cout << "-1\n";
        }
        else {
            if(dis<max_dis && dis>min_dis) {
                cout << "2\n";
            }
            else if(dis==max_dis || dis==min_dis) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
    }
    
    return 0;
}