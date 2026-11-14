#include <stdio.h>
#include <stdbool.h>

float calculateSum(int n, float g_1, float g_2, float g_3, float g_4, float g_5, float g_6, float g_7, float g_8, float g_9, float g_10) 
{
    float sum = 0.0f;
    if (n >= 1 && g_1 >= 0) 
    {
        sum += g_1;
    }
    if (n >= 2 && g_2 >= 0) 
    {
        sum += g_2;
    }
    if (n >= 3 && g_3 >= 0) 
    {
        sum += g_3;
    }
    if (n >= 4 && g_4 >= 0) 
    {
        sum += g_4;
    }
    if (n >= 5 && g_5 >= 0) 
    {
        sum += g_5;
    }
    if (n >= 6 && g_6 >= 0) 
    {
        sum += g_6;
    }
    if (n >= 7 && g_7 >= 0) 
    {
        sum += g_7;
    }
    if (n >= 8 && g_8 >= 0) 
    {
        sum += g_8;
    }
    if (n >= 9 && g_9 >= 0) 
    {
        sum += g_9;
    }
    if (n >= 10 && g_10 >= 0) 
    {
        sum += g_10;
    }
    return sum;
}

float calculateAvg(int n, float sum) 
{
    if (n == 0) 
    {
        return 0.0f;
    }
    return sum / n;
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
    switch (w) 
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

bool isSessionInvalid(int t, int a)
{
    return !((t >= 0 && t <= 30) && (a >= 0 && a <= 30) && (t - a >= 0));
}

float calculateAbsentRate(int t, int a)
{
    if (t == 0)
    {
        return 0.0f;
    }
    return ((float)a / t) * 100.0f;
}

int readValidInput(int min, int max, int promptId)
{
    int val;
    bool isInvalid;
    do 
    {
        switch (promptId) 
        {
            case 1: 
                printf("Insert the number of credits: "); 
                break;
            case 2: 
                printf("Enter semester: "); 
                break;
            case 3: 
                printf("Enter number of studying days per week (1-3): "); 
                break;
            case 4: 
                printf("Enter weekday for day 1: "); 
                break;
            case 5:
                printf("Enter weekday for day 2: ");
                break;
            case 6: 
                printf("Enter weekday for day 3: "); 
                break;
            case 7: 
                printf("Enter total sessions: "); 
                break;
            case 8: 
                printf("Enter absent sessions: "); 
                break;
        }
        scanf("%d", &val);
        isInvalid = !(val >= min && val <= max);

        if (isInvalid)
        {
            if (promptId == 1)
            {
                printf("Credits only from 0 to 20, please retry\n");
            }
            else if (promptId == 7 || promptId == 8)
            {
                printf("Error: Not valid, retry.\n");
            }
            else
            {
                printf("Error: not valid, please retry.\n");
            }
        }
    } while (isInvalid);
    return val;
}

int readAttendance()
{
    int t, a;
    bool isTAInvalid;
    do
    {
        t = readValidInput(0, 30, 7);
        a = readValidInput(0, 30, 8);
        
        isTAInvalid = isSessionInvalid(t, a);        
        if (isTAInvalid)
        {
            printf("Error: Not valid, retry.\n");
        }
    } while (isTAInvalid);
    
    return t * 100 + a;
}

int readExactSchedule(int weekday)
{
    int promptId = (weekday == 1) ? 4 : ((weekday == 2) ? 5 : 6);
    int w = readValidInput(2, 8, promptId);

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

bool isDateInvalid(int d, int m, int y) 
{
    if (y < 2026 || y > 2032 || m < 1 || m > 12 || d < 1) 
    {
        return true;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) 
    {
        return d > 30;
    }
    if (m == 2) 
    {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        return isLeap ? (d > 29) : (d > 28);
    }
    return d > 31;
}

bool isPeriodInvalid(int d1, int m1, int y1, int d2, int m2, int y2) 
{
    if (y2 < y1) 
    {
        return true;
    }    
    if (y2 == y1 && m2 < m1)
    { 
        return true;
    }
    if (y2 == y1 && m2 == m1 && d2 <= d1) 
    {
        return true;
    }
    return false;
}

int main()
{
    int x = readValidInput(0, 20, 1);
    int s = readValidInput(1, 2147483647, 2);
    int d = readValidInput(1, 3, 3);    

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

    int attendanceData = readAttendance();
    int t = attendanceData / 100;
    int a = attendanceData % 100;

    float r = calculateAbsentRate(t, a);

    int n;
    bool isNInvalid;
    do 
    {
        printf("Enter number of tests: ");
        scanf("%d", &n);
        isNInvalid = !(n >= 0 && n <= 10);
        if (isNInvalid) 
        {
            printf("Error: Entry must be between 0 and 10\n");
        }
    } while (isNInvalid);

    float g;
    float g_1 = -1, g_2 = -1, g_3 = -1, g_4 = -1, g_5 = -1, g_6 = -1, g_7 = -1, g_8 = -1, g_9 = -1, g_10 = -1;
    bool isGInvalid;

    for (int i = 1; i <= n; i++) 
    {
        do 
        {
            printf("Enter grade for test %d: ", i);
            scanf("%f", &g);
            isGInvalid = !(g >= 0.0 && g <= 10.0);
            if (isGInvalid) 
            {
                printf("Error: Entry must be between 0.0 and 10.0\n");
            }
        } while (isGInvalid);
        
        switch (i)
        {
            case 1:
                g_1 = g;
                break;

            case 2:
                g_2 = g;
                break;
            
            case 3:
                g_3 = g;
                break;
            
            case 4:
                g_4 = g;
                break;
            
            case 5:
                g_5 = g;
                break;
            
            case 6:
                g_6 = g;
                break;
            
            case 7:
                g_7 = g;
                break;
            
            case 8:
                g_8 = g;
                break;

            case 9:
                g_9 = g;
                break;

            case 10:
                g_10 = g;
                break;

            default:
                break;
        }
    }

    float finalSum = calculateSum(n, g_1, g_2, g_3, g_4, g_5, g_6, g_7, g_8, g_9, g_10);
    float finalAvg = calculateAvg(n, finalSum);
    
    int d_1, m_1, y_1;
    int d_2, m_2, y_2;
    bool isDatePeriodInvalid;
    
    do 
    {
        printf("Enter beginning date (DD MM YYYY): ");
        scanf("%d %d %d", &d_1, &m_1, &y_1);
        
        printf("Enter ending date (DD MM YYYY): ");
        scanf("%d %d %d", &d_2, &m_2, &y_2);
        
        isDatePeriodInvalid = isDateInvalid(d_1, m_1, y_1) || 
                              isDateInvalid(d_2, m_2, y_2) || 
                              isPeriodInvalid(d_1, m_1, y_1, d_2, m_2, y_2);
        
        if (isDatePeriodInvalid) 
        {
            printf("Error, not valid, please retry.\n");
        }
    } while (isDatePeriodInvalid);

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
    printf("Grades: ");
    for (int i = 1; i <= n; i++) 
    {
        switch (i)
        {
            case 1:
                printf("%.1f", g_1); 
                break;

            case 2:
                printf("%.1f", g_2);
                break;
            
            case 3:
                printf("%.1f", g_3);
                break;
            
            case 4:
                printf("%.1f", g_4); 
                break;
            
            case 5:
                printf("%.1f", g_5); 
                break;
            
            case 6:
                printf("%.1f", g_6); 
                break;
            
            case 7:
                printf("%.1f", g_7);
                break;
            
            case 8:
                printf("%.1f", g_8);
                break;

            case 9:
                printf("%.1f", g_9); 
                break;

            case 10:
                printf("%.1f", g_10);
                break;

            default:
                break;
        }   
        if (i < n) 
        {
            printf(", ");
        }
    }
    printf(" | Sum: %.1f, Avg: %.1f\n", finalSum, finalAvg);
    printf("Beginning time: %02d/%02d/%04d\n", d_1, m_1, y_1);
    printf("Ending time: %02d/%02d/%04d\n", d_2, m_2, y_2);
    return 0;
}
