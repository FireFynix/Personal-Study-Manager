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
    
    int w_1, h1_1, m1_1, h2_1, m2_1;
    int w_2, h1_2, m1_2, h2_2, m2_2;
    int w_3, h1_3, m1_3, h2_3, m2_3;
    bool isWInvalid;
    bool isH1H2M1M2Invalid;

    if (d >= 1) 
    {
        do 
        {
            printf("Enter weekday for day 1: ");
            scanf("%d", &w_1);
            isWInvalid = !(w_1 >= 2 && w_1 <= 8);
            if (isWInvalid)
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isWInvalid);

        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_1, &m1_1, &h2_1, &m2_1);
            isH1H2M1M2Invalid = !((h1_1 >= 0 && h1_1 <= 23) && (h2_1 >= 0 && h2_1 <= 23) && (m1_1 >= 0 && m1_1 <= 59) && (m2_1 >= 0 && m2_1 <= 59) && ((h2_1 * 60 + m2_1) > (h1_1 * 60 + m1_1)));
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, pls retry.\n");
            }    
        } while (isH1H2M1M2Invalid);
    }

    if (d >= 2) 
    {
        do 
        {
            printf("Enter weekday for day 2: ");
            scanf("%d", &w_2);
            isWInvalid = !(w_2 >= 2 && w_2 <= 8);
            if (isWInvalid)
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isWInvalid);

        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_2, &m1_2, &h2_2, &m2_2);
            isH1H2M1M2Invalid = !((h1_2 >= 0 && h1_2 <= 23) && (h2_2 >= 0 && h2_2 <= 23) && (m1_2 >= 0 && m1_2 <= 59) && (m2_2 >= 0 && m2_2 <= 59) && ((h2_2 * 60 + m2_2) > (h1_2 * 60 + m1_2)));
            if (isH1H2M1M2Invalid)
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isH1H2M1M2Invalid);
    }

    if (d == 3) 
    {
        do 
        {
            printf("Enter weekday for day 3: ");
            scanf("%d", &w_3);
            isWInvalid = !(w_3 >= 2 && w_3 <= 8);
            if (isWInvalid)
            {
                printf("Error: not valid, pls retry.\n");
            }
        } while (isWInvalid);

        do 
        {
            printf("Enter start time (h1, m1) and end time (h2, m2): ");
            scanf("%d %d %d %d", &h1_3, &m1_3, &h2_3, &m2_3);
            isH1H2M1M2Invalid = !((h1_3 >= 0 && h1_3 <= 23) && (h2_3 >= 0 && h2_3 <= 23) && (m1_3 >= 0 && m1_3 <= 59) && (m2_3 >= 0 && m2_3 <= 59) && ((h2_3 * 60 + m2_3) > (h1_3 * 60 + m1_3)));
            if (isH1H2M1M2Invalid) 
            {
                printf("Error: not valid, pls retry.\n");
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

    int n;
    bool isNInvalid;
    do 
    {
        printf("Enter number of tests: ");
        scanf("%d", &n);
        isNInvalid = !(n >= 0 && n <= 10);
        if (isNInvalid) 
        {
            printf("Error: Entry must be between 0.0 and 10.0\n");
        }
    } while (isNInvalid);

    float sum = 0.0, g;
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

        if (i == 1) 
        {
            g_1 = g;
        }
        else if (i == 2) 
        {
            g_2 = g;
        }
        else if (i == 3)
        {
            g_3 = g;
        }
        else if (i == 4)
        {
            g_4 = g;
        }
        else if (i == 5) 
        {
            g_5 = g;
        }
        else if (i == 6) 
        {
            g_6 = g;
        }    
        else if (i == 7)
        {
            g_7 = g;  
        }
        else if (i == 8) 
        {
            g_8 = g;
        }
        else if (i == 9) 
        {
            g_9 = g;
        }
        else if (i == 10) 
        {
            g_10 = g;
        }
        sum += g;
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
    printf("Grades: ");
    for (int i = 1; i <= n; i++) 
    {
        if (i == 1) 
        {
            printf("%.1f", g_1);
        }
        else if (i == 2)
        {
            printf("%.1f", g_2);
        }
        else if (i == 3) 
        {
            printf("%.1f", g_3);
        }
        else if (i == 4) 
        {
            printf("%.1f", g_4);
        }
        else if (i == 5) 
        {
            printf("%.1f", g_5);
        }
        else if (i == 6) 
        {
            printf("%.1f", g_6);
        }
        else if (i == 7) 
        {
            printf("%.1f", g_7);
        }
        else if (i == 8) 
        {
            printf("%.1f", g_8);
        }
        else if (i == 9) 
        {
            printf("%.1f", g_9);
        }
        else if (i == 10) 
        {
            printf("%.1f", g_10);
        }
        if (i < n) 
        {
            printf(", ");
        }
    }
    printf(" | Sum: %.1f", sum); 
    printf("\n");    
    return 0;
}
