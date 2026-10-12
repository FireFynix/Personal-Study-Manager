#include<iostream>


int main()
{
    int n;
    std::cout <<"Insert the number of credits: ";
    std::cin >> n;
    while( n > 20 || n < 0)
    {
        std::cout << "Retry from 0 - 20: ";
        std::cin >> n; 
    } 
    std::cout << "Your subject's credits currently: " << n << std::endl;
    return 0;
}
