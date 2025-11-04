#include <iostream>
#include <vector>

using namespace std;

bool nprime[10000001];
int result[10000001];

bool check(int num) {
    int nt = num;
    int ns[8];
    int l = 0;
    
    while(nt > 0) {
        ns[l] = nt % 10;
        l++;
        nt /= 10;
    }
    
    for(int i=l-1; i>0; i--) {
        int c = ns[i];
        
        for(int j=i-1; j>=0; j--) {
            if(i==l-1 && j==0)
                break;
            
            c *= 10;
            c += ns[j];
            
            if(nprime[c])
                return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    vector<int> v;
    
    cin >> t;
    
    for(int i=2; i<=10000000; i++)
        if(!nprime[i])
            for(int j=i+i; j<=10000000; j+=i)
                nprime[j] = true;
    
    for(int i=100; i<=10000000; i++)
        if(nprime[i] && check(i))
            v.push_back(i);
    
    int l = 0;
    for(int i=1; i<=10000000; i++) {
        if(l<v.size()-1 && i>=v[l+1])
            l++;
        
        result[i] = v[l];
        
        if(l==0 && i<v[l])
            result[i] = -1;
    }
    
    for(int i=0; i<t; i++) {
        int num;
        
        cin >> num;
        
        cout << result[num] << "\n";
    }
    
    return 0;
}