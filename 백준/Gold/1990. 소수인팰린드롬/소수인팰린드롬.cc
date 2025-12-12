#include <iostream>

using namespace std;

int a, b;

bool check(int num) {
    if(num%2 == 0)
        return false;
    
    for(int i=3; i*i<=num; i+=2)
        if(num%i == 0)
            return false;
    
    return true;
}

int reverse(int n) {
    int result = 0;
    int temp = n;
    
    while(temp > 0) {
        result *= 10;
        result += temp % 10;
        temp /= 10;
    }
    
    return result;
}

bool make(int size) {
    if(size == 1) {
        for(int i=5; i<10; i++) {
            if(i < a)
                continue;
            
            if(i > b)
                return false;
            
            if(check(i))
                cout << i << "\n";
        }
        
        return true;
    }
    
    int half = size / 2;
    int s=1, e=1;
    
    for(int i=1; i<half; i++)
        s *= 10;
    
    for(int i=0; i<half; i++)
        e *= 10;
    
    for(int i=s; i<e; i++) {
        if(size%2 == 1) {
            for(int j=0; j<10; j++) {
                int num = i * 10 + j;
                
                for(int k=0; k<half; k++)
                    num *= 10;
                
                num += reverse(i);
                
                if(num < a)
                    continue;
                
                if(num > b)
                    return false;
                
                if(check(num))
                    cout << num << "\n";
            }
        }
        
        else {
            int num = i;
            
            for(int k=0; k<half; k++)
                num *= 10;
            
            num += reverse(i);
            
            if(num < a)
                continue;
            
            if(num > b)
                return false;
            
            if(check(num))
                cout << num << "\n";
        }
    }
    
    return true;
}

int main() {
    cin >> a >> b;
    
    for(int i=1; i<=8; i++)
        if(!make(i))
            break;
    
    cout << "-1";
    
    return 0;
}