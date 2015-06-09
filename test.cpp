#include<stdio.h>

/* const int BITSTEPWORD = sizeof(int) * 8; */
/* const SHIFT = BITSTEPWORD == 32? 5 : 10; */
/* const MASK = */ 

#define SHIFT 5
#define MASK 0x1F
#define NUM 10000000
int array[1 + NUM / BITSTEPWORD];

void set(int i){
    array[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i){
    array[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i){
    return array[i >> SHIFT] & (1 << (i & MASK));
}


int main(int argc, char *argv[])
{
    int a = 0x00F5;
    printf("%X \n", a);
    printf("%d \n", a);


    printf("%d\n", (a & 0x1F));
    return 0;
}
