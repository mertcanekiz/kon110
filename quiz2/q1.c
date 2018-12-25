#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#if !defined(_WIN32) && !defined(__CYGWIN__)
char *strrev(char *str)
{
    char *p1, *p2;
    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
#endif

int main(int argc, char* argv[])
{
    char buf[100];
    while (true) {
        printf("Please enter a string: ");
        gets(buf);
        strrev(buf);
        printf("%s\n", buf);
    }
}
