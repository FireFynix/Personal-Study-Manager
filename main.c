#include<stdio.h>

int main()
{
    int n;
    printf("Insert the number of credits: ");
    scanf("%d", &n);
    while( n > 20 || n < 0)
    {
        printf("Retry from 0 - 20: ");
        scanf("%d", &n); 
    }
    printf("Your subject's credits currently: %d\n", n);
    return 0;
}
