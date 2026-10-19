#include<stdio.h>

int main()
{
    int x;

    printf("Insert the number of credits: ");
    scanf("%d", &x);
    
    while(!(x >= 0 && x <= 20))
    {
        printf("Credits only from 0 to 20, please retry\n");
        printf("Insert the number of credits: ");
        scanf("%d", &x);
    }
    
    printf("Your subject's credits currently: %d\n", x);
   
    return 0;
}
