#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    int temp = 0;
    temp++;
    while ((c = getchar()) != EOF)
    {
        temp++;
        printf("c\n");
    }
    return 0;
}
