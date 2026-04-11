#include <iostream>

using namespace std;

string a, b, c;
int visit[201][201];

int find(int as, int bs, int cs) {
    if(cs == c.size())
        return 1;
    
    if(visit[as][bs] != -1)
        return visit[as][bs];
    
    if(as<a.size() && a[as]==c[cs] && bs<b.size() && b[bs]==c[cs])
        return (visit[as+1][bs]=find(as+1, bs, cs+1)) | (visit[as][bs+1]=find(as, bs+1, cs+1));
    
    else if(as<a.size() && a[as]==c[cs])
        return visit[as+1][bs] = find(as+1, bs, cs+1);
    
    else if(bs<b.size() && b[bs]==c[cs])
        return visit[as][bs+1] = find(as, bs+1, cs+1);
    
    else
        return 0;
}

int main() {
    int t;
    
    cin >> t;
    
    for(int i=1; i<=t; i++) {
        cin >> a >> b >> c;
        
        for(int j=0; j<=a.size(); j++)
            for(int k=0; k<=b.size(); k++)
                visit[j][k] = -1;
        
        cout << "Data set " << i << ": ";
        
        if(find(0, 0, 0) == 1)
            cout << "yes";
        
        else
            cout << "no";
        
        cout << "\n";
    }
    
    return 0;
}