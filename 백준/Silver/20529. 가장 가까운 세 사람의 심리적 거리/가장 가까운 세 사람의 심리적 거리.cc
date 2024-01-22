#include <iostream>
#include <vector>

using namespace std;

vector<int> cal_dis(vector<string> s, int p) {
	vector<int> result;
	string target = s[p];
	
	for(int i=0; i<s.size(); i++) {
		int dis = 0;
		string other = s[i];
		
		for(int j=0; j<4; j++)
			if(target[j] != other[j])
				dis++;
		
		result.push_back(dis);
	}
	
	return result;
}

int find(vector<vector<int>> v) {
	int result = 8;
	
	for(int i=0; i<v.size()-2; i++) {
		for(int j=i+1; j<v.size()-1; j++) {
			for(int k=j+1; k<v.size(); k++) {
				int temp = v[i][j] + v[i][k] + v[j][k];
				
				if(result > temp)
					result = temp;
			}
		}
	}
	
	return result;
}

int main() {
    int T;
    
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int n;
        string str = "";
        
        cin >> n;
   
        vector<string> strs;
        
        for(int j=0; j<n; j++) {
        	cin >> str;
            strs.push_back(str);
        }
        
        if(n >= 48) {
            cout << 0 << endl;
        }
        
        else {
            vector<vector<int>> v;
        
            for(int j=0; j<n; j++)
        	    v.push_back(cal_dis(strs, j));
        
            cout << find(v) << endl;
        }
    }
    
    return 0;
}