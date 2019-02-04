#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int num_set[10];
    int c, ac;

    for (int i = 0; i < 10; i++)
        num_set[i] = 0;

    while ((c = getchar()) != EOF)
    {
        ac++;
        if (c >= '0' && c <= '9')
            num_set[c - '0'] = num_set[c - '0'] + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        int len = num_set[i];
        char bar[len + 1];
        for (int j = 0; j < len; j++)
            bar[j] = '-';
        bar[len] = 0;

        printf("%d %2.d %s\n", i, num_set[i], bar);
    }

    return 0;
}
