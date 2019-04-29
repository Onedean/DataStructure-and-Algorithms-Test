#include <stdio.h>
int main()
{
    float distance, wait;
    int count;
    scanf("%f %f", &distance, &wait);
    distance = (int)(distance + 0.5);
    wait = (int)(wait / 5);
    count = distance <= 3 ? 10 : (distance <= 10 ? 2 * distance + 4 : 3 * distance - 6);
    count += 2 * wait;
    printf("%d", count);
    return 0;
}