#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define OUT_WORD 0
#define IN_WORD 1
#define WORD_BUF_LEN 100

int main(int argc, char const *argv[])
{
    int max = atoi(argv[1]);
    if (max <= 0 || max > 80)
        return 0;

    // printf("(%3.d) %d\n", __LINE__, max);

    int c;      /* Char. */
    int cc = 0; /* Position. */
    int fb = 0; /* Position of blanks in front of each word. */
    int bb = 0; /* Position of blanks behind each word. */
    int state = OUT_WORD;
    int word_len = 0;
    char *word_buffer = (char *)malloc(WORD_BUF_LEN);

    while ((c = getchar()) != EOF)
    {
        cc++;
        // printf("(%3.d) cc %d\n", __LINE__, cc);
        if (c == ' ' || c == '\n') /* Find a separator. */
        {
            // printf("(%3.d) find a sep\n", __LINE__);
            fb = bb;
            bb = cc;
            if (bb <= max + 1) /* Print last word. No new line. */
            {
                // printf("(%3.d) print word: %s\n", __LINE__, word_buffer);
                printf("%s ", word_buffer);
                memset(word_buffer, 0, word_len);
                word_len = 0;
                continue;
            }
            else
            {
                // printf("(%3.d) new line\n", __LINE__);
                if (fb <= max + 1) /* Dont't print last word. Start a new line.*/
                {
                    printf("\n%s ", word_buffer);
                    // printf("(%3.d) current word: %s\n", __LINE__, word_buffer);
                    // printf("(%3.d) 1. bb %d; fb %d; cc %d; word_len %d\n", __LINE__, bb, fb, cc, word_len);
                    memset(word_buffer, 0, word_len);
                    word_len = 0;
                    bb = bb - fb;
                    cc = bb;
                    fb = 0;
                    // printf("(%3.d) 2. bb %d; fb %d; cc %d;\n", __LINE__, bb, fb, cc);
                    continue;
                }
                assert(0);
            }
        }
        else /* Find a char. */
        {
            // printf("(%3.d) find a char\n", __LINE__);
            word_buffer[word_len++] = c;
        }
    }
    return 0;
}
