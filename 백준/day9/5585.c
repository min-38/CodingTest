#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int result = 0;
    int changes = 1000 - N;

    while(changes > 0)
    {
        if(changes >= 500)
        {
            changes -= 500;
        }
        else if(changes >= 100)
        {
            changes -= 100;
        }
        else if(changes >= 50)
        {
            changes -= 50;
        }
        else if(changes >= 10)
        {
            changes -= 10;
        }
        else if(changes >= 5)
        {
            changes -= 5;
        }
        else
        {
            changes -= 1;
        }
        result++;
    }

    printf("%d\n", result);

    return 0;
}