#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10];
    char s2[10];
    char s3[20];
    scanf("%s", s1);
    scanf("%s", s2);
    strcpy(s3, s1);
    strcat(s3, s2);
    printf("%s\n", s3);
    printf("hello world!\n");
    return 0;
}
