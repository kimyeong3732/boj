#include <iostream>
#include <vector>

using namespace std;

int n;
int p[48], s[48];
bool visit[48];
vector<int> cycle;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

void find(int index, int size) {
    visit[index] = true;
    
    if(visit[s[index]]) {
        if(size != 1)
            cycle.push_back(size);
        
        return;
    }
    
    find(s[index], size+1);
}

bool check() {
    for(int i=0; i<n; i++)
        if(p[i] != i%3)
            return false;
    
    return true;
}

void shuffle() {
    int temp[48];
    
    for(int i=0; i<n; i++)
        temp[s[i]] = p[i];
    
    for(int i=0; i<n; i++)
        p[i] = temp[i];
}

int main() {
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> p[i];
    
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    for(int i=0; i<n; i++)
        if(!visit[i])
            find(i, 1);
    
    int total;
    
    if(cycle.size() == 0) {
        total = 1;
    }
    
    else {
        total = cycle[0];
        int lcm = cycle[0];
        
        for(int i=1; i<cycle.size(); i++) {
            total *= cycle[i];
            lcm = total / gcd(lcm, cycle[i]);
        }
        
        total = lcm;
    }
    
    int count = 0;
    
    for(; count<total; count++) {
        if(check())
            break;
        
        shuffle();
    }
    
    if(count == total)
        count = -1;
    
    cout << count;
    
    return 0;
}