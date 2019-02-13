#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GAP ('A' - 'a')

int main(int argc, char const *argv[])
{
    int len = strlen(argv[argc - 1]);
    char *str = (char *)malloc((len + 1) * sizeof(char));
    strncpy(str, argv[argc - 1], len);
    printf("before %s\n", str);

    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        str[i] = c < 'a' ? (c - GAP) : c;
    }
    printf("after  %s\n", str);
    return 0;
}
