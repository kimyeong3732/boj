#include <cstdio>

struct point {
    long long x, y;
    
    bool operator < (const point & a) const {
        if(x == a.x)
            return y < a.y;
        
        return x < a.x;
    }
    bool operator <= (const point & a) const {
        if(x == a.x)
            return y <= a.y;
        
        return x <= a.x;
    }
};

int ccw(point a, point b, point c) {
    long long s = a.x*b.y + b.x*c.y + c.x*a.y;
    s -= a.x*c.y + b.x*a.y + c.x*b.y;
    
    if(s < 0)
        return -1;
        
    else if(s > 0)
        return 1;
        
    else
        return 0;
}

int main() {
    point a1, a2;
    point b1, b2;
    
    scanf("%lld%lld%lld%lld", &a1.x, &a1.y, &a2.x, &a2.y);
    scanf("%lld%lld%lld%lld", &b1.x, &b1.y, &b2.x, &b2.y);
    
    int a = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int b = ccw(b1, b2, a1) * ccw(b1, b2, a2);
    
    if(a==0 && b==0) {
        point as = a1;
        point ab = a2;
        point bs = b1;
        point bb = b2;
        
        if(ab < as) {
            as = a2;
            ab = a1;
        }
        if(bb < bs) {
            bs = b2;
            bb = b1;
        }
        
        if(as<=bb && bs<=ab)
            printf("1\n");
        else
            printf("0\n");
    }
    
    else if(a<=0 && b<=0)
        printf("1\n");
    
    else
        printf("0\n");
    
    return 0;
}