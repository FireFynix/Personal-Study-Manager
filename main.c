#include<stdio.h>
#include<stdbool.h>

int getValidWeekday() 
{
    int w;
    bool isInvalid;
    do 
    {
        scanf("%d", &w);
        isInvalid = !(w >= 2 && w <= 8);
        if (isInvalid) 
        {
            printf("Error: not valid, please retry.\n");
        }
    } while (isInvalid);
    return w;
}

bool isTimeInvalid(int h1, int m1, int h2, int m2) 
{
    bool isStartHourValid   = h1 >= 0 && h1 <= 23;
    bool isEndHourValid     = h2 >= 0 && h2 <= 23;
    bool isStartMinuteValid = m1 >= 0 && m1 <= 59;
    bool isEndMinuteValid   = m2 >= 0 && m2 <= 59;
    bool isEndAfterStart    = (h2 * 60 + m2) > (h1 * 60 + m1);
    return !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);
}

void printWeekday(int w) 
{
    switch(w) 
    {
        case 2: 
            printf("Monday"); 
            break;
        case 3: 
            printf("Tuesday"); 
            break;
        case 4: 
            printf("Wednesday"); 
            break;
        case 5: 
            printf("Thursday"); 
            break;
        case 6: 
            printf("Friday"); 
            break;
        case 7: 
            printf("Saturday"); 
            break;
        case 8: 
            printf("Sunday"); 
            break;
        default: 
            break;
    }
}

int StartTimeEndTime()
{
    int h1, m1, h2, m2;
    bool isInvalidTime;
    do 
    {
        printf("Enter start time (h1, m1) and end time (h2, m2): ");
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        isInvalidTime = isTimeInvalid(h1, m1, h2, m2);
        if (isInvalidTime) 
        {
            printf("Error: not valid, please retry.\n");
        }
    } while (isInvalidTime);

}

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
            printf("Error: not valid, please retry.\n");
        }
    } while (isSInvalid);

    int d;
    bool isDInvalid;
    do
    {
        printf("Enter number of studying days per week (1-3): ");
        scanf("%d", &d);
        isDInvalid = !(d >= 1 && d <= 3);
        if(isDInvalid)
        {
            printf("Error: not valid, please retry.\n");
        }
    } while (isDInvalid);

    int w_1, h1_1, m1_1, h2_1, m2_1;
    int w_2, h1_2, m1_2, h2_2, m2_2;
    int w_3, h1_3, m1_3, h2_3, m2_3;


    if (d >= 1) 
    {
        printf("Enter weekday for day 1: ");
        w_1 = getValidWeekday();

        h1_1 = StartTimeEndTime();
        m1_1 = StartTimeEndTime();
        
    }

    if (d >= 2)
    {
        printf("Enter weekday for day 2: ");
        w_2 = getValidWeekday();

        h1_2 = StartTimeEndTime();
        m1_2 = StartTimeEndTime();
    }

    if (d == 3) 
    {
        printf("Enter weekday for day 3: ");
        w_3 = getValidWeekday();

        h1_2 = StartTimeEndTime();
        m1_2 = StartTimeEndTime();
    }

    int t, a;
    bool isTAInvalid;
    do 
    {
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
    } 
    else 
    {
        r = ((float)a / t) * 100.0;
    }

    printf("Your subject's credits currently: %d\n", x);
    printf("Current semester: %d\n", s);
    printf("Number of studying days per week: %d\n", d);
    printf("Schedule: "); 

    if (d >= 1)
    {
        printWeekday(w_1);
        printf(" %02d:%02d - %02d:%02d", h1_1, m1_1, h2_1, m2_1);
    }

    if (d >= 2)
    {
        printf(", ");
        printWeekday(w_2);
        printf(" %02d:%02d - %02d:%02d", h1_2, m1_2, h2_2, m2_2);
    }

    if (d == 3)
    {
        printf(", ");
        printWeekday(w_3);
        printf(" %02d:%02d - %02d:%02d", h1_3, m1_3, h2_3, m2_3);
    }

    printf("\n");    
    printf("Total sessions: %d, Absent sessions: %d | Non - Attendance Rate: %.2f%%\n", t, a, r);
    return 0;
}
