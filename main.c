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
    
    int s;
    do {
        printf("Enter semester: ");
        scanf("%d", &s);
        if (!(s > 0)) {
            printf("Error: not valid, pls retry.\n");
        }
    } while (!(s > 0));

    int d;
    do {
        printf("Enter number of studying days per week (1-3): ");
        scanf("%d", &d);
        if (!(d >= 1 && d <= 3)) {
            printf("Error: not valid, pls retry.\n");
        }
    } while (!(d >= 1 && d <= 3));

    int w, h1, m1, h2, m2;
    for (int i = 1; i <= d; i++) 
    {
        do {
            printf("Enter weekday for day %d: ", i);
            scanf("%d", &w);
            if (!(w >= 2 && w <= 8)) {
                printf("Error: not valid, pls retry.\n");
            }
        } while (!(w >= 2 && w <= 8));

        do {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
            if (!((h1 >= 0 && h1 <= 23) && (h2 >= 0 && h2 <= 23) && (m1 >= 0 && m1 <= 59) && (m2 >= 0 && m2 <= 59) && ((h2 * 60 + m2) > (h1 * 60 + m1)))) 
            {
                printf("Error: not valid, pls retry.\n");
            }
        } 
        while (!((h1 >= 0 && h1 <= 23) && (h2 >= 0 && h2 <= 23) && (m1 >= 0 && m1 <= 59) && (m2 >= 0 && m2 <= 59) && ((h2 * 60 + m2) > (h1 * 60 + m1))));

        printf("Schedule: Day %d %02d:%02d - %02d:%02d\n", w, h1, m1, h2, m2);
    }
        char dayName[10];
        if (w == 2) sprintf(dayName, "Monday");
        else if (w == 3) sprintf(dayName, "Tuesday");
        else if (w == 4) sprintf(dayName, "Wednesday");
        else if (w == 5) sprintf(dayName, "Thursday");
        else if (w == 6) sprintf(dayName, "Friday");
        else if (w == 7) sprintf(dayName, "Saturday");
        else if (w == 8) sprintf(dayName, "Sunday");

        printf("Schedule: %s %02d:%02d - %02d:%02d\n", dayName, h1, m1, h2, m2);
    return 0;
}
