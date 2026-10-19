#include<stdio.h>
#include<stdbool.h>

int main()
{
    int x;
    bool isXInvalid;
    do
    {
        printf("Insert the number of credits: ");
        scanf("%d", &x);
        isXInvalid = !(x >= 0 && x <= 20);
        if(isXInvalid)
        {
            printf("Credits only from 0 to 20, please retry\n");
        }
    }
    while(isXInvalid);
    printf("Your subject's credits currently: %d\n", x);
   
    return 0;
}
