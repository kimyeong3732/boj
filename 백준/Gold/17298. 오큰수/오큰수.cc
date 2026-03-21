#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int input[1000000];
int result[1000000];

int main() {
    int n;
    
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> input[i];
    
    result[n-1] = -1;
    st.push(input[n-1]);
    
    for(int i=n-2; i>=0; i--) {
        while(!st.empty() && input[i]>=st.top())
            st.pop();
        
        if(st.empty())
            result[i] = -1;
        
        else
            result[i] = st.top();
        
        st.push(input[i]);
    }
    
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    
    cout << "\n";
    
    return 0;
}