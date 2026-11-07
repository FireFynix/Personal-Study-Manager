#include <stdio.h>
#include <stdbool.h>

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
    switch (w) 
    {
        case 2: printf("Monday"); break;
        case 3: printf("Tuesday"); break;
        case 4: printf("Wednesday"); break;
        case 5: printf("Thursday"); break;
        case 6: printf("Friday"); break;
        case 7: printf("Saturday"); break;
        case 8: printf("Sunday"); break;
        default: break;
    }
}

int readValidInput(int min, int max, int isCredit)
{
    int val;
    bool isInvalid;
    do 
    {
        scanf("%d", &val);
        isInvalid = !(val >= min && val <= max);
        if (isInvalid) 
        {
            if (isCredit == 1) 
            {
                printf("Credits only from 0 to 20, please retry\n");
            } 
            else 
            {
                printf("Error: not valid, please retry.\n");
            }
        }
    } while (isInvalid);
    return val;
}

int readExactSchedule(int weekday)
{
    int w, h1, m1, h2, m2;
    bool isWInvalid, isInvalidTime;

    do 
    {
        printf("Enter weekday for day %d: ", weekday);
        scanf("%d", &w);
        isWInvalid = !(w >= 2 && w <= 8);
        if (isWInvalid) 
        {
            printf("Error: not valid, please retry.\n");
        }
    } while (isWInvalid);

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

    return w * 100000000 + h1 * 1000000 + m1 * 10000 + h2 * 100 + m2;
}

void printDecodedSchedule(int eT)
{
    int m2 = eT % 100;
    int h2 = (eT / 100) % 100;
    int m1 = (eT / 10000) % 100;
    int h1 = (eT / 1000000) % 100;
    int w  = eT / 100000000;

    printWeekday(w);
    printf(" %02d:%02d - %02d:%02d", h1, m1, h2, m2);
}

int main()
{
    
    printf("Insert the number of credits: ");
    int x = readValidInput(0, 20, 1);

    printf("Enter semester: ");
    int s = readValidInput(1, 2147483647, 0);

    printf("Enter number of studying days per week (1-3): ");
    int d = readValidInput(1, 3, 0);

    int eT_1 = 0, eT_2 = 0, eT_3 = 0;

    if (d >= 1) 
    {
        eT_1 = readExactSchedule(1);
    }
    if (d >= 2) 
    {
        eT_2 = readExactSchedule(2);
    }
    if (d == 3) 
    {
        eT_3 = readExactSchedule(3);
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
        printDecodedSchedule(eT_1);
    }
    if (d >= 2) 
    {
        printf(", ");
        printDecodedSchedule(eT_2);
    }
    if (d == 3) 
    {
        printf(", ");
        printDecodedSchedule(eT_3);
    }

    printf("\n");
    printf("Total sessions: %d, Absent sessions: %d | Non - Attendance Rate: %.2f%%\n", t, a, r);

    return 0;
}