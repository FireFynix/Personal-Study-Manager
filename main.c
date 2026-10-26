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
   
    int s;
    bool isSInvalid;
    do
    {
        printf("Enter semester: ");
        scanf("%d", &s);
        isSInvalid = !(s > 0);
        if(isSInvalid)
        {
            printf("Error: not valid, pls retry.\n");
        }
    } while (isSInvalid);

    int d;
    bool isDInvalid;
    do
    {
        printf("Enter number of studying days per week (1-3): ");
        scanf("%d",&d);
        isDInvalid = !(d >= 1 && d <= 3);
        if(isDInvalid)
        {
            printf("Error: not valid, pls retry.\n");
        }
    } while (isDInvalid);
    
    printf("Your subject's credits currently: %d\n", x);
    printf("Current semester: %d\n", s);
    printf("Number of studying days per week: %d\n", d);

    return 0;
}
