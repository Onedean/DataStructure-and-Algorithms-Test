#include <stdio.h>
#include <string.h>
int main()
{
    char ch[100];
    scanf("%s", &ch);
    if (strlen(ch) > 1)
    {
        printf("您的输入无法识别！\n");
        return 0;
    }
    switch (ch[0])
    {
    case 'Y':
    case 'y':
        printf("您选择的是同意！\n");
        break;
    case 'N':
    case 'n':
        printf("您选择的是拒绝！\n");
        break;
    default:
        printf("您的输入无法识别！\n");
        break;
    }
    return 0;
}