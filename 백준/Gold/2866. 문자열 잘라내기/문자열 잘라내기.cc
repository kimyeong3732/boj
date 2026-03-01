#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, c;
	string input[1000];
	string ms[1000];

	cin >> n >> c;

	for(int i=0; i<n; i++)
		cin >> input[i];

	for(int i=0; i<c; i++) {
        string temp = "";
        
		for(int j=0; j<n; j++)
            temp += input[j][i];
        
        ms[i] = temp;
	}
	
	int result = 0;
	bool state = false;
	
    for(int i=0; i<n; i++) {
        set<string> s;
        
        for(int j=0; j<c; j++) {
            ms[j] = ms[j].substr(1);
            
            if(s.find(ms[j]) == s.end()) {
                s.insert(ms[j]);
            }
            
            else {
                state = true;
                break;
            }
        }
        
        if(state)
            break;
        
        result++;
	}
	
	cout << result;
	
	return 0;
}