#include <iostream>
#include <algorithm>

using namespace std;

int n;
int result = -1;
bool astate = false;
bool bstate = false;
int anum, bnum;
int a_array[500000];
int b_array[500000];

void array_init(int start, int delta, bool is_a) {
    int count = 1;
    if(is_a)
        a_array[start] = 0;
    else
        b_array[start] = 0;
        
    int left = start;
    int right = start;
    
    while(true) {
        left = (left + n - delta) % n;
        right = (right + delta) % n;
        
        if(is_a) {
            if(a_array[left] != -1) {
                if(a_array[left] == a_array[(left+delta)%n]) {
                    astate = true;
                    anum = count;
                }
                
                return;
            }
            
            a_array[left] = count;
            a_array[right] = count;
        }
        else {
            if(b_array[left] != -1) {
                if(b_array[left] == b_array[(left+delta)%n]) {
                    bstate = true;
                    bnum = count;
                }
                
                return;
            }
            
            b_array[left] = count;
            b_array[right] = count;
        }
        
        count++;
    }
}

void position_calc() {
    for(int i=0; i<n; i++) {
        int a = a_array[i];
        int b = b_array[i];
        
        int temp = 0;
        
        if(a<0 || b<0)
            continue;
        
        if(a < b) {
            if(astate && b>=(anum*2-a-1))
                a = b;
            else {
                if((b-a)%2 == 1)
                    a = b + 1;
                else
                    a = b;
            }
        }
        
        if(bstate && a>(bnum*2-b-1))
            b = a - 1;
        
        temp = a * 2;
            
        if((a-b)%2 == 1)
            temp--;
        
        if(result<0 || result>temp)
            result = temp;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int as, bs;
    int da, db;
    
    cin >> n >> as >> bs >> da >> db;
    
    for(int i=0; i<n; i++) {
        a_array[i] = -1;
        b_array[i] = -1;
    }
    
    array_init(as-1, da, true);
    array_init(bs-1, db, false);
    
    position_calc();
    
    if(result < 0)
        cout << "Evil Galazy";
    else
        cout << result;
    
    return 0;
}