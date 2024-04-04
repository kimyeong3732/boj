#include <iostream>
#include <vector>

using namespace std;

bool nums[4000000];
vector<int> prime;

void init() {
    for(int i=2; i<2000000; i++)
        if(!nums[i])
            for(int j=2; i*j<4000000; j++)
                nums[i*j] = true;
                
    for(int i=2; i<4000000; i++)
        if(!nums[i])
            prime.push_back(i);
}

int main() {
    init();
    
    int num;
    int count = 0;
    
    cin >> num;
    
    int begin = 0;
    int end = 0;
    int sum = prime[0];
    
    while(begin <= end) {
        if(sum <= num) {
            if(sum == num)
                count++;
            
            end++;
            if(end == prime.size())
                break;
            sum += prime[end];
        }
        else {
            sum -= prime[begin];
            begin++;
        }
    }
    
    cout << count;
    
    return 0;
}