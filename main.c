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
    
    int w, h1, m1, h2, m2;
    bool isWInvalid;
    bool isH1H2M1M2Invalid;
    char dayName[10];

    for (int i = 1; i <= d; i++) {
        do {
            printf("Enter weekday for day %d: ", i);
            scanf("%d", &w);
            isWInvalid = !(w >= 2 && w <= 8);
            if (isWInvalid) 
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isWInvalid);

        do{
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
            isH1H2M1M2Invalid = !((h1 >= 0 && h1 <= 23) && (h2 >= 0 && h2 <= 23) && (m1 >= 0 && m1 <= 59) && (m2 >= 0 && m2 <= 59) && ((h2 * 60 + m2) > (h1 * 60 + m1)));
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isH1H2M1M2Invalid); 
    }       
    
    if (w == 2) sprintf(dayName, "Monday");
    else if (w == 3) sprintf(dayName, "Tuesday");
    else if (w == 4) sprintf(dayName, "Wednesday");
    else if (w == 5) sprintf(dayName, "Thursday");
    else if (w == 6) sprintf(dayName, "Friday");
    else if (w == 7) sprintf(dayName, "Saturday");
    else if (w == 8) sprintf(dayName, "Sunday");

    int t, a;
    bool isTAInvalid;
    do {
        printf("Enter total sessions: ");
        scanf("%d", &t);
        printf("Enter absent sessions: ");
        scanf("%d", &a);
        isTAInvalid = !((t >= 0 && t <= 30) && (a >= 0 && a <= 30) && (t - a >= 0));
        if (isTAInvalid) 
        {
            printf("Error: Not valid, retry.\n");
        }
    } while (isTAInvalid);

    float r;
    if (t == 0) 
    {
        r = 0.0;
    } else {
        r = ((float)a / t) * 100.0;
    }

    printf("Your subject's credits currently: %d\n", x);
    printf("Current semester: %d\n", s);
    printf("Number of studying days per week: %d\n", d);
    printf("Schedule: %s %02d:%02d - %02d:%02d\n", dayName, h1, m1, h2, m2);    
    printf("Total sessions: %d, Absent sessions: %d | Non - Attendance Rate: %.2f%%\n", t, a, r);

    return 0;
}
