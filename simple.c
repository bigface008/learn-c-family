#include <stdio.h>
#include <stdlib.h>

struct NODE_ {
    int num;
    int type;
}

void internal(const char str0[], char str1[])
{
    str0 += 10;
    str1 += 10;
    int i = 0;
    while (i <= 10) {
        printf("Hello world!\n");
    }
}

int main(int argc, char const *argv[])
{
    printf("%d", 010);
    return 0;
}
