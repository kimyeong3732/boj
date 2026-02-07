#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<int> v;

  int mn = 2000000001;

  cin >> n;

  for(int i=0; i<n; i++) {
    int num;

    cin >> num;

    v.push_back(num);
  }

  sort(v.begin(), v.end());

  int l=0, r=v.size()-1;
  int lr=0, rr=v.size()-1;
  
  while(l < r) {
    int d = v[r] + v[l];

    int dt = d;
    
    if(dt < 0)
      dt *= -1;
    
    if(mn > dt){
      lr = l;
      rr = r;
      mn = dt;
    }
    
    if(d < 0)
      l++;
    else if(d > 0)
      r--;
    else
      break;
  }

  cout << v[lr] << " " << v[rr];

  return 0;
}