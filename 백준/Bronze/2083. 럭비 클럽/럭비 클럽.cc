#include <cstdio>
#include <cstring>

int main() {
    while(1) {
        char name[11];
        int age, w;
        
        scanf("%s%d%d", name, &age, &w);
        
        if((strcmp(name, "#")==0) && (age==0) && (w==0))
            break;
        
        printf("%s ", name);
        
        if((age>17) || (w>=80))
            printf("Senior\n");
        else
            printf("Junior\n");
    }
    
    return 0;
}