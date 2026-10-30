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

    return 0;
}
