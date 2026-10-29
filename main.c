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
    } while(isXInvalid);
   
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
    
    int w_arr[3], h1_arr[3], m1_arr[3], h2_arr[3], m2_arr[3];
    bool isWInvalid;
    bool isH1H2M1M2Invalid;
    char dayName[10];

    for (int i = 1; i <= d; i++) 
    {
        do 
        {
            printf("Enter weekday for day %d: ", i);
            scanf("%d", &w_arr[i-1]); 
            isWInvalid = !(w_arr[i-1] >= 2 && w_arr[i-1] <= 8);
            if (isWInvalid) 
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isWInvalid);

        do
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_arr[i-1], &m1_arr[i-1], &h2_arr[i-1], &m2_arr[i-1]);
            isH1H2M1M2Invalid = !((h1_arr[i-1] >= 0 && h1_arr[i-1] <= 23) && 
                                  (h2_arr[i-1] >= 0 && h2_arr[i-1] <= 23) && 
                                  (m1_arr[i-1] >= 0 && m1_arr[i-1] <= 59) && 
                                  (m2_arr[i-1] >= 0 && m2_arr[i-1] <= 59) && 
                                  ((h2_arr[i-1] * 60 + m2_arr[i-1]) > (h1_arr[i-1] * 60 + m1_arr[i-1])));
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isH1H2M1M2Invalid); 
    }       
    

    printf("Your subject's credits currently: %d\n", x);
    printf("Current semester: %d\n", s);
    printf("Number of studying days per week: %d\n", d);
    printf("Schedule: "); 
    for (int i = 0; i < d; i++) 
    {
        if (w_arr[i] == 2) sprintf(dayName, "Monday");
        else if (w_arr[i] == 3) sprintf(dayName, "Tuesday");
        else if (w_arr[i] == 4) sprintf(dayName, "Wednesday");
        else if (w_arr[i] == 5) sprintf(dayName, "Thursday");
        else if (w_arr[i] == 6) sprintf(dayName, "Friday");
        else if (w_arr[i] == 7) sprintf(dayName, "Saturday");
        else if (w_arr[i] == 8) sprintf(dayName, "Sunday");

        printf("%s %02d:%02d - %02d:%02d", dayName, h1_arr[i], m1_arr[i], h2_arr[i], m2_arr[i]);

        if (i < d - 1) 
        {
            printf(", ");
        }
    }
    printf("\n");    
    return 0;
}
