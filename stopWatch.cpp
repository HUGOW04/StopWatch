#include <iostream>
#include <Windows.h>

void displayTime(int hours, int minutes, int seconds)
{
    system("cls");
    std::cout << hours << ":" << minutes << ":" << seconds<<std::endl;
}

int main()
{
    int hour = 0; 
    int minute = 0;
    int second = 0;

    while (true)
    {
        Sleep(1);
        second++;
        if (second > 59)
        {
            minute++;
            second = 0;
        }
        if (minute > 59)
        {
            hour++;
            minute = 0;
            second = 0;
        }
        displayTime(hour, minute, second);
    }
}
