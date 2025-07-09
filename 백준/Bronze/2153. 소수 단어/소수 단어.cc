#include <iostream>

using namespace std;

int main() {
    bool prime[1041];
    
    for(int i=1; i<1041; i++)
        prime[i] = true;
    
    for(int i=2; i<1041; i++)
        if(prime[i])
            for(int j=i*2; j<1041; j+=i)
                if(prime[j])
                    prime[j] = false;
    
    string s;
    int num = 0;
    
    cin >> s;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i]>='a' && s[i]<='z')
            num += s[i] - 'a' + 1;
        else
            num += s[i] - 'A' + 27;
    }
    
    
    cout << "It is ";
    
    if(!prime[num])
        cout << "not ";
    
    cout << "a prime word.";
    
    return 0;
}