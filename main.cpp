#include <iostream>
#include <iomanip>

int main()
{
    int x;
    bool isXInvalid;
    do
    {
        std::cout << "Insert the number of credits: ";
        std::cin >> x;
        isXInvalid = !(x >= 0 && x <= 20);
        if(isXInvalid)
        {
            std::cout << "Credits only from 0 to 20, please retry\n";
        }
    } while(isXInvalid);

    int s;
    bool isSInvalid;
    do
    {
        std::cout << "Enter semester: ";
        std::cin >> s;
        isSInvalid = !(s > 0);
        if(isSInvalid)
        {
            std::cout << "Error: not valid, please retry.\n";
        }
    } while (isSInvalid);

    int d;
    bool isDInvalid;
    do
    {
        std::cout << "Enter number of studying days per week (1-3): ";
        std::cin >> d;
        isDInvalid = !(d >= 1 && d <= 3);
        if(isDInvalid)
        {
            std::cout << "Error: not valid, please retry.\n";
        }
    } while (isDInvalid);

    int w_1, h1_1, m1_1, h2_1, m2_1;
    int w_2, h1_2, m1_2, h2_2, m2_2;
    int w_3, h1_3, m1_3, h2_3, m2_3;
    bool isWInvalid;
    bool isH1H2M1M2Invalid;
    bool isStartHourValid;
    bool isEndHourValid;
    bool isStartMinuteValid;
    bool isEndMinuteValid;
    bool isEndAfterStart;

    if (d >= 1)
    {
        do
        {
            std::cout << "Enter weekday for day 1: ";
            std::cin >> w_1;
            isWInvalid = !(w_1 >= 2 && w_1 <= 8);
            if (isWInvalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isWInvalid);

        do
        {
            std::cout << "Enter start time (h1, m1) and end time (h2, m2): ";
            std::cin >> h1_1 >> m1_1 >> h2_1 >> m2_1;

            isStartHourValid= h1_1 >= 0 && h1_1 <= 23;
            isEndHourValid = h2_1 >= 0 && h2_1 <= 23;
            isStartMinuteValid = m1_1 >= 0 && m1_1 <= 59;
            isEndMinuteValid = m2_1 >= 0 && m2_1 <= 59;
            isEndAfterStart = (h2_1 * 60 + m2_1) > (h1_1 * 60 + m1_1);

            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);

            if (isH1H2M1M2Invalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isH1H2M1M2Invalid);
    }

    if (d >= 2)
    {
        do
        {
            std::cout << "Enter weekday for day 2: ";
            std::cin >> w_2;
            isWInvalid = !(w_2 >= 2 && w_2 <= 8);
            if (isWInvalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isWInvalid);

        do
        {
            std::cout << "Enter start time (h1, m1) and end time (h2, m2): ";
            std::cin >> h1_2 >> m1_2 >> h2_2 >> m2_2;

            isStartHourValid   = h1_2 >= 0 && h1_2 <= 23;
            isEndHourValid     = h2_2 >= 0 && h2_2 <= 23;
            isStartMinuteValid = m1_2 >= 0 && m1_2 <= 59;
            isEndMinuteValid   = m2_2 >= 0 && m2_2 <= 59;
            isEndAfterStart    = (h2_2 * 60 + m2_2) > (h1_2 * 60 + m1_2);

            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);

            if (isH1H2M1M2Invalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isH1H2M1M2Invalid);
    }

    if (d == 3)
    {
        do
        {
            std::cout << "Enter weekday for day 3: ";
            std::cin >> w_3;
            isWInvalid = !(w_3 >= 2 && w_3 <= 8);
            if (isWInvalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isWInvalid);

        do
        {
            std::cout << "Enter start time (h1, m1) and end time (h2, m2): ";
            std::cin >> h1_3 >> m1_3 >> h2_3 >> m2_3;

            isStartHourValid   = h1_3 >= 0 && h1_3 <= 23;
            isEndHourValid     = h2_3 >= 0 && h2_3 <= 23;
            isStartMinuteValid = m1_3 >= 0 && m1_3 <= 59;
            isEndMinuteValid   = m2_3 >= 0 && m2_3 <= 59;
            isEndAfterStart    = (h2_3 * 60 + m2_3) > (h1_3 * 60 + m1_3);

            isH1H2M1M2Invalid = !(isStartHourValid && isEndHourValid && isStartMinuteValid && isEndMinuteValid && isEndAfterStart);

            if (isH1H2M1M2Invalid)
            {
                std::cout << "Error: not valid, please retry.\n";
            }
        } while (isH1H2M1M2Invalid);
    }

    int t, a;
    bool isTAInvalid;
    do
    {
        std::cout << "Enter total sessions: ";
        std::cin >> t;
        std::cout << "Enter absent sessions: ";
        std::cin >> a;
        isTAInvalid = !((t >= 0 && t <= 30) && (a >= 0 && a <= 30) && (t - a >= 0));
        if (isTAInvalid)
        {
            std::cout << "Error: Not valid, retry.\n";
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

    std::cout << "Your subject's credits currently: " << x << "\n";
    std::cout << "Current semester: " << s << "\n";
    std::cout << "Number of studying days per week: " << d << "\n";
    std::cout << "Schedule: ";

    if (d >= 1)
    {
        switch(w_1)
        {
            case 2:
                std::cout << "Monday";
                break;
            case 3:
                std::cout << "Tuesday";
                break;
            case 4:
                std::cout << "Wednesday";
                break;
            case 5:
                std::cout << "Thursday";
                break;
            case 6:
                std::cout << "Friday";
                break;
            case 7:
                std::cout << "Saturday";
                break;
            case 8:
                std::cout << "Sunday";
                break;
            default:
                break;
        }

        if (h1_1 < 10) 
        {
            std::cout << " 0" << h1_1 << ":"; 
        }
        else 
        {
            std::cout << " " << h1_1 << ":";
        }
        
        if (m1_1 < 10) 
        {
            std::cout << "0" << m1_1 << " - ";
        } 
        else 
        {
            std::cout << m1_1 << " - ";
        }

        if (h2_1 < 10) 
        {
            std::cout << "0" << h2_1 << ":"; 
        }
        else
        {
            std::cout << h2_1 << ":";
        }
        
        if (m2_1 < 10) 
        {
            std::cout << "0" << m2_1; 
        }
        else 
        {
            std::cout << m2_1;
        }
    }

    if (d >= 2)
    {
        std::cout << ", ";
        switch(w_2)
        {
            case 2:
                std::cout << "Monday";
                break;
            case 3:
                std::cout << "Tuesday";
                break;
            case 4:
                std::cout << "Wednesday";
                break;
            case 5:
                std::cout << "Thursday";
                break;
            case 6:
                std::cout << "Friday";
                break;
            case 7:
                std::cout << "Saturday";
                break;
            case 8:
                std::cout << "Sunday";
                break;
            default:
                break;
        }

        if (h1_2 < 10)
        { 
            std::cout << " 0" << h1_2 << ":"; 
        }
        else 
        {
            std::cout << " " << h1_2 << ":";
        }

        if (m1_2 < 10)
        { 
            std::cout << "0" << m1_2 << " - "; 
        }
        else 
        {
            std::cout << m1_2 << " - ";
        }

        if (h2_2 < 10)
        { 
        std::cout << "0" << h2_2 << ":"; 
        }
        else 
        {
            std::cout << h2_2 << ":";
        }

        if (m2_2 < 10) 
        {
            std::cout << "0" << m2_2;
        } 
        else 
        {
            std::cout << m2_2;
        }
    }

    if (d == 3)
    {
        std::cout << ", ";
        switch(w_3)
        {
            case 2:
                std::cout << "Monday";
                break;
            case 3:
                std::cout << "Tuesday";
                break;
            case 4:
                std::cout << "Wednesday";
                break;
            case 5:
                std::cout << "Thursday";
                break;
            case 6:
                std::cout << "Friday";
                break;
            case 7:
                std::cout << "Saturday";
                break;
            case 8:
                std::cout << "Sunday";
                break;
            default:
                break;
        }
        
        if (h1_3 < 10) 
        {
            std::cout << " 0" << h1_3 << ":";
        } 
        else 
        { 
            std::cout << " " << h1_3 << ":";
        }

        if (m1_3 < 10) 
        {
            std::cout << "0" << m1_3 << " - ";
        } 
        else 
        {
            std::cout << m1_3 << " - ";
        }

        if (h2_3 < 10) 
        {
            std::cout << "0" << h2_3 << ":";
        }
        else 
        {
            std::cout << h2_3 << ":";
        }

        if (m2_3 < 10) 
        {
            std::cout << "0" << m2_3;
        } 
        else 
        {
            std::cout << m2_3;
        }
    }

    std::cout << "\n";
    
    std::cout << "Total sessions: " << t << ", Absent sessions: " << a << " | Non - Attendance Rate: ";
    std::cout << std::fixed << std::setprecision(2) << r << "%" << std::endl;

    return 0;
}
