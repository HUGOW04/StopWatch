#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;

class alarm
{
private:
    tm askedTime, currentTime, diffrenceinTime;
    time_t now;
public:
    alarm()
    {
        now = time(0);
        currentTime = *localtime(&now);
        askedTime = currentTime;
        askedTime.tm_sec = 0;
    }

    void getTime()
    {
        string Time;
        cout<<"Enter time in 24h format [HH:MM] : ";
        getline(cin,Time);
        int pos = 0, h;
        while ((pos = Time.find(':')) != string::npos)
        {
            string token = Time.substr(0,pos);
            stringstream convert (token);
            convert>> askedTime.tm_hour;
            Time.erase(0,pos+1);
        }
        stringstream convert (Time);
        convert >> askedTime.tm_min;
        
    }

    void timeDiffrence()
    {
        int seconds = difftime(mktime(&askedTime),now);
        diffrenceinTime.tm_min = seconds / 60;
        diffrenceinTime.tm_hour = diffrenceinTime.tm_min / 60;
        diffrenceinTime.tm_min = diffrenceinTime.tm_min % 60;
        diffrenceinTime.tm_sec = seconds % 60;
        if(seconds < 0)
        {
            diffrenceinTime.tm_hour = 24 + diffrenceinTime.tm_hour - 1;
            diffrenceinTime.tm_min = 0 - diffrenceinTime.tm_min;
            diffrenceinTime.tm_sec = 0 - diffrenceinTime.tm_sec;
        }
    }
    
    void start_alarm()
    {
        while (true)
        {
            system("cls");
            now = time(0);
            currentTime = *localtime(&now);
            timeDiffrence();
            cout<<"Time Remaining: "<<diffrenceinTime.tm_hour<<":"<<diffrenceinTime.tm_min<<":"<<diffrenceinTime.tm_sec;
            if(diffrenceinTime.tm_hour == 0 && diffrenceinTime.tm_min == 0 && diffrenceinTime.tm_sec == 0)
            {
                cout<<endl<<"Times Up"<<endl<<"Press CTRL+C to stop"<<endl;
                break;
            }
        }
        
    }
};

int main()
{
    alarm myAlarm;
    myAlarm.getTime();
    myAlarm.start_alarm();
    for(int i = 0; ;i+=50)
    {
        Beep(i,1000);
    }
}
