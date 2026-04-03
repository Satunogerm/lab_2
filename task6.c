#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

struct Variant {
    union Data data;
    int type;  // 1=int, 2=float, 3=char
};

int main() {
    // Task 1 & 2: Union stores only one value
    union Data d;
    
    d.i = 100;
    printf("int: %d\n", d.i);
    printf("float: %f (garbage)\n", d.f);
    printf("char: %c (garbage)\n\n", d.c);
    
    d.f = 3.14;
    printf("float: %.2f\n", d.f);
    printf("int: %d (garbage)\n\n", d.i);
    
    d.c = 'X';
    printf("char: %c\n", d.c);
    printf("int: %d (garbage)\n\n", d.i);
    
    // Task 3: Structure with type tracking
    struct Variant v;
    
    v.data.i = 64;
    v.type = 1;
    printf("Type 1 (int): %d\n", v.data.i);
    
    v.data.f = 8.88;
    v.type = 2;
    printf("Type 2 (float): %.2f\n", v.data.f);
    
    v.data.c = 'Q';
    v.type = 3;
    printf("Type 3 (char): %c\n", v.data.c);
    
    return 0;
}