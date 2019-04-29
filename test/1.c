#include <stdio.h>
int main()
{
    int a[6] = {10, 20, 30, 40, 50}, num, count = 5;
    scanf("%d", &num);
    for (int i = 0; i < 5; i++)
    {
        if (num < a[i])
        {
            count = i;
            break;
        }
    }
    for (int i = 5; i > count; i--)
    {
        a[i] = a[i - 1];
    }
    a[count] = num;
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}