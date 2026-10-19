#include<stdio.h>

int main()
{
    int x;
    int isXValid;
    do
    {
        printf("Insert the number of credits: ");
        scanf("%d", &x);
        isXValid = !(x >= 0 && x <= 20);
        if(isXValid == 1)
        {
            printf("Credits only from 0 to 20, please retry\n");
        }
    }
    while(isXValid == 1);
    printf("Your subject's credits currently: %d\n", x);
   
    return 0;
}
