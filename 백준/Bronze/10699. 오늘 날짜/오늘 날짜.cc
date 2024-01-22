#include <cstdio>
#include <ctime>

int main() {
    time_t timer = time(NULL);
    
    struct tm* t = localtime(&timer);
    
    printf("%d-", t->tm_year + 1900);
    
    if(t->tm_mon < 9) printf("0");
    printf("%d-", t->tm_mon + 1);
    
    if(t->tm_mday < 10) printf("0");
    printf("%d\n", t->tm_mday);
    
    return 0;
}