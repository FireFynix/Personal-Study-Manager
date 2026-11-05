#include<stdio.h>
#include<stdbool.h>

int getValidInt(const char* prompt, const char* errorMsg, int min, int max) 
{
    int value;
    bool isInvalid;
    do 
    {
        printf("%s", prompt);
        scanf("%d", &value);
        isInvalid = !(value >= min && value <= max);
        if (isInvalid) 
        {
            printf("%s", errorMsg);
        }
    } while (isInvalid);
    return value;
}

int main()
{
    int x = getValidInt("Insert the number of credits: ", "Credits only from 0 to 20, please retry\n", 0, 20);
    int s = getValidInt("Enter semester: ", "Error: not valid, please retry.\n", 1, 2147483647);
    int d = getValidInt("Enter number of studying days per week (1-3): ", "Error: not valid, please retry.\n", 1, 3);
    
    int w_1, h1_1, m1_1, h2_1, m2_1;
    int w_2, h1_2, m1_2, h2_2, m2_2;
    int w_3, h1_3, m1_3, h2_3, m2_3;
    bool isH1H2M1M2Invalid;
    bool isStartHourValid;   
    bool isEndHourValid;     
    bool isStartMinuteValid; 
    bool isEndMinuteValid;   
    bool isEndAfterStart;
    if (d >= 1) 
    {
        w_1 = getValidInt("Enter weekday for day 1: ", "Error: not valid, please retry.\n", 2, 8);
        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_1, &m1_1, &h2_1, &m2_1);
            isStartHourValid   = h1_1 >= 0 && h1_1 <= 23;
            isEndHourValid     = h2_1 >= 0 && h2_1 <= 23;
            isStartMinuteValid = m1_1 >= 0 && m1_1 <= 59;
            isEndMinuteValid   = m2_1 >= 0 && m2_1 <= 59;
            isEndAfterStart    = (h2_1 * 60 + m2_1) > (h1_1 * 60 + m1_1);
            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, please retry.\n");
            }    
        } while (isH1H2M1M2Invalid);
    }

    if (d >= 2) 
    {
        w_2 = getValidInt("Enter weekday for day 2: ", "Error: not valid, please retry.\n", 2, 8);
        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_2, &m1_2, &h2_2, &m2_2);
            isStartHourValid   = h1_2 >= 0 && h1_2 <= 23;
            isEndHourValid     = h2_2 >= 0 && h2_2 <= 23;
            isStartMinuteValid = m1_2 >= 0 && m1_2 <= 59;
            isEndMinuteValid   = m2_2 >= 0 && m2_2 <= 59;
            isEndAfterStart    = (h2_2 * 60 + m2_2) > (h1_2 * 60 + m1_2);
            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);
            if (isH1H2M1M2Invalid)
            {
                printf("Error: not valid, please retry.\n");
            }
        } while (isH1H2M1M2Invalid);
    }

    if (d == 3) 
    {
        w_3 = getValidInt("Enter weekday for day 3: ", "Error: not valid, please retry.\n", 2, 8);
        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_3, &m1_3, &h2_3, &m2_3);
            isStartHourValid   = h1_3 >= 0 && h1_3 <= 23;
            isEndHourValid     = h2_3 >= 0 && h2_3 <= 23;
            isStartMinuteValid = m1_3 >= 0 && m1_3 <= 59;
            isEndMinuteValid   = m2_3 >= 0 && m2_3 <= 59;
            isEndAfterStart    = (h2_3 * 60 + m2_3) > (h1_3 * 60 + m1_3);
            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, please retry.\n");
            }    
        } while (isH1H2M1M2Invalid);
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
        switch(w_1)
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
        printf(" %02d:%02d - %02d:%02d", h1_1, m1_1, h2_1, m2_1);
    }

    if (d >= 2) 
    {
        printf(", ");
        switch(w_2)
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
        printf(" %02d:%02d - %02d:%02d", h1_2, m1_2, h2_2, m2_2);
    }    

    if (d == 3) 
    {
        printf(", ");
        switch(w_3)
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
        printf(" %02d:%02d - %02d:%02d", h1_3, m1_3, h2_3, m2_3);
    }
    printf("\n");    
    printf("Total sessions: %d, Absent sessions: %d | Non - Attendance Rate: %.2f%%\n", t, a, r);
    return 0;
}
