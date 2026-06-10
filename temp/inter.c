#include <stdio.h>

struct p {
    int x;
    char y[5];
};

int main() {
    struct p m1 = {0};
    
    printf("%d %s",m1.x,m1.y);
    
    
    return 0;
}
