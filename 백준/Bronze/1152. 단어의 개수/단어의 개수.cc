#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int count = 1;
    string s;
    
    getline(cin, s);
    
    for(int i=0; i<s.length()-1; i++)
      if(s[i] == ' ')
          count++;
    
    if(s[0] == ' ') count--;
    
    cout << count << endl;
    
    return 0;
}