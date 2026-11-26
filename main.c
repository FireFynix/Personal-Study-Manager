#include <stdio.h>
#include <stdbool.h>

float calculateSum(float grades[], int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        sum += grades[i];
    }
    return sum;
}

float calculateAvg(int n, float sum)
{
    if (n == 0)
    {
        return 0.0f;
    }
    int sum10 = (int)(sum * 10.0f + 0.5f);
    int avg10 = (2 * sum10 + n) / (2 * n);
    return avg10 / 10.0f;
}

bool isTimeInvalid(int h1, int m1, int h2, int m2) 
{
    bool isStartHourValid   = h1 >= 0 && h1 <= 23;
    bool isEndHourValid     = h2 >= 0 && h2 <= 23;
    bool isStartMinuteValid = m1 >= 0 && m1 <= 59;
    bool isEndMinuteValid   = m2 >= 0 && m2 <= 59;
    bool isEndAfterStart    = (h2 * 60 + m2) > (h1 * 60 + m1);
    return (!(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart));
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
    return ((((float) a) / t) * 100.0f);
}

int readValidInput(int min, int max, int promptId)
{
    long long val;
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
            case 9:
                printf("Enter number of tests: ");
                break;
            case 10:
                printf("Enter number of subjects (1-10): ");
                break;
            case 11:
                printf("Enter semester to search: ");
                break;
        }
        scanf("%lld", &val);
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
            else if (promptId == 9 || promptId == 10)
            {
                printf("Error: Entry must be between 1 and 10\n");
            }
            else
            {
                printf("Error: not valid, please retry.\n");
            }
        }
    } while (isInvalid);
    return (int)val;
}

int readAttendance(void)
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
    
    return (t * 100 + a);
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

    return (w * 100000000 + h1 * 1000000 + m1 * 10000 + h2 * 100 + m2);
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

void readSchedule(int eT[], int d)
{
    for (int i = 0; i < d; i++)
    {
        eT[i] = readExactSchedule(i + 1);
    }
}

void printSchedule(int eT[], int d)
{
    for (int i = 0; i < d; i++)
    {
        printDecodedSchedule(eT[i]);
        if (i < d - 1)
        {
            printf(", ");
        }
    }
}

bool isDateInvalid(int d, int m, int y) 
{
    if (y < 2026 || y > 2032 || m < 1 || m > 12 || d < 1) 
    {
        return true;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) 
    {
        return (d > 30);
    }
    if (m == 2) 
    {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        return (isLeap ? (d > 29) : (d > 28));
    }
    return (d > 31);
}

bool isPeriodInvalid(int beginDate, int endDate) 
{
    return (endDate <= beginDate); 
}

int readExactDate(int promptId) 
{
    int d, m, y;
    int currentDate;
    bool isInvDate;
    
    do 
    {
        if (promptId == 1) 
        {
            printf("Enter beginning date (DD MM YYYY): ");
        } 
        else 
        {
            printf("Enter ending date (DD MM YYYY): ");
        }
        scanf("%d %d %d", &d, &m, &y);
        
        isInvDate = isDateInvalid(d, m, y);
        currentDate = y * 10000 + m * 100 + d;
        
        if (isInvDate) 
        {
            printf("Error, not valid, please retry.\n");
        }
    } while (isInvDate);
    
    return currentDate;
}

void readGrades(float grades[], int n)
{
    float g;
    bool isGInvalid;

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Enter grade for test %d: ", i + 1);
            scanf("%f", &g);
            isGInvalid = !(g >= 0.0f && g <= 10.0f);
            if (isGInvalid)
            {
                printf("Error: Entry must be between 0.0 and 10.0\n");
            }
        } while (isGInvalid);

        g = ((int)(g * 10.0f + 0.5f)) / 10.0f;

        grades[i] = g;
    }
}

long long readPeriod(void) 
{
    int beginDate, endDate;
    bool isPeriodInv;
    
    do 
    {
        beginDate = readExactDate(1);
        endDate = readExactDate(2);
        
        isPeriodInv = isPeriodInvalid(beginDate, endDate);
        
        if (isPeriodInv) 
        {
            printf("Error, not valid, please retry.\n");
        }
    } while (isPeriodInv);
    
    return (((long long) beginDate) * 100000000 + endDate);
}

void printExactDate(int dateVal) 
{
    int y = dateVal / 10000;
    int m = (dateVal / 100) % 100;
    int d = dateVal % 100;

    printf("%02d/%02d/%04d\n", d, m, y);
}

void printGradebook(int numSubjects, int numTests[], float grades[][10], float finalAvg[])
{
    printf("\n=== Multi-Subject Gradebook ===\n");
    for (int i = 0; i < numSubjects; i++)
    {
        printf("Subject %d | Grades: ", i + 1);
        for (int j = 0; j < numTests[i]; j++)
        {
            printf("%.1f", grades[i][j]);
            if (j < numTests[i] - 1)
            {
                printf(", ");
            }
        }
        printf(" | Avg: %.1f\n", finalAvg[i]);
    }
}

int main(void)
{
    int numSubjects = readValidInput(1, 10, 10);

    int credits[10];
    int semesters[10];
    int d[10];
    int eT[10][3];
    int t[10];
    int a[10];
    float r[10];
    int numTests[10];
    float grades[10][10];
    float finalSum[10];
    float finalAvg[10];
    int beginningDate[10];
    int endingDate[10];

    for (int i = 0; i < numSubjects; i++)
    {
        printf("\n--- Subject %d ---\n", i + 1);

        credits[i] = readValidInput(0, 20, 1);
        semesters[i] = readValidInput(1, 2147483647, 2); // 2147483647 is the largest value for an 'int', which also means its value is greater than 0.
        d[i] = readValidInput(1, 3, 3);

        readSchedule(eT[i], d[i]);

        int attendanceData = readAttendance();
        t[i] = attendanceData / 100;
        a[i] = attendanceData % 100;
        r[i] = calculateAbsentRate(t[i], a[i]);

        numTests[i] = readValidInput(1, 10, 9);
        readGrades(grades[i], numTests[i]);

        finalSum[i] = calculateSum(grades[i], numTests[i]);
        finalAvg[i] = calculateAvg(numTests[i], finalSum[i]);

        long long periodData = readPeriod();
        beginningDate[i] = periodData / 100000000;
        endingDate[i] = periodData % 100000000;
    }

    printf("\n");
    int searchS = readValidInput(1, 2147483647, 11);

    int foundCount = 0;
    int totalCredits = 0;

    printf("\n=== Subjects in Semester %d ===\n", searchS);
    for (int i = 0; i < numSubjects; i++)
    {
        if (semesters[i] == searchS)
        {
            foundCount++;
            totalCredits += credits[i];

            printf("\n--- Subject %d ---\n", i + 1);
            printf("Your subject's credits currently: %d\n", credits[i]);
            printf("Current semester: %d\n", semesters[i]);
            printf("Number of studying days per week: %d\n", d[i]);

            printf("Schedule: ");
            printSchedule(eT[i], d[i]);
            printf("\n");

            printf("Total sessions: %d, Absent sessions: %d | Non - Attendance Rate: %.2f%%\n", t[i], a[i], r[i]);

            printf("Grades: ");
            for (int j = 0; j < numTests[i]; j++)
            {
                printf("%.1f", grades[i][j]);
                if (j < numTests[i] - 1)
                {
                    printf(", ");
                }
            }
            printf(" | Sum: %.1f, Avg: %.1f\n", finalSum[i], finalAvg[i]);

            printf("Beginning time: ");
            printExactDate(beginningDate[i]);
            printf("Ending time: ");
            printExactDate(endingDate[i]);
        }
    }

    if (foundCount == 0)
    {
        printf("No subjects found for this semester.\n");
    }
    printf("Total credits for semester %d: %d\n", searchS, totalCredits);

    printGradebook(numSubjects, numTests, grades, finalAvg);

    return 0;
}
