#include <iostream>

using namespace std;

int nums[26];

int main() {
    string s;
    
    while(getline(cin, s))
        for(int i=0; i<s.size(); i++)
            if(s[i] != ' ')
                nums[s[i]-'a']++;
    
    int max = 0;
    
    for(int i=0; i<26; i++)
        if(max < nums[i])
            max = nums[i];
    
    for(int i=0; i<26; i++)
        if(nums[i] == max)
            cout << (char)(i + 'a');
    
    return 0;
}