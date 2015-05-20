#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int main ()
{
    float caryover_seconds;
    float caryover_minutes;
    float caryover_hours;
    float caryover_days;
    float caryover_months;
    float caryover_years;
    float birthyear;
	time_t now = time(0);
	tm*ltm = localtime(&now);
	float seconds = ltm->tm_sec;
	float minute = ltm->tm_min;
	float hour = ltm->tm_hour;
	float year = 1900+ltm->tm_year;
	float month = 1+ltm->tm_mon;
	float day = ltm->tm_mday;
  string input = "";
  float birthseconds;
  cout << "Enter the second you were born (ex. 9:00:09 would be 9) (if unknown put 0)" << endl;
  cin >> birthseconds;
  float seconds_after_hour = birthseconds-seconds;
  if (seconds_after_hour < 0)
  {
                         caryover_seconds = 1;
                         seconds_after_hour = 60+seconds_after_hour;
  }
  float birthminute;
  cout << "Enter the minute you were born (if unknown put 0)" << endl;
  cin >> birthminute;
  float minutes_in_seconds = ((birthminute + caryover_seconds) - minute)*60;
  if (minutes_in_seconds <0)
  {
                         caryover_minutes = 1;
                         minutes_in_seconds = 3600 + minutes_in_seconds;
  }
  float birthhour;
  cout << "Enter the hour you were born as a number between 0 and 24 (if unknown put 0)" << endl;
  cin >> birthhour;
  float hours_in_seconds = ((birthhour + caryover_minutes) - hour)*3600;
  if (hours_in_seconds < 0)
  {
                       caryover_hours = 1;
                       hours_in_seconds = 86400 + hours_in_seconds;
  }
  float birthday;
  cout << "Enter the day of the month you were born" << endl;
  cin >> birthday;
  float days_in_seconds = ((birthday + caryover_hours) - day)*86400;
  if (days_in_seconds < 0)
  {
                      caryover_days = 1;
                      days_in_seconds = ((365.25/12)*86400)+days_in_seconds;
  }
  float birthmonth;
  cout << "Enter your birth month as a number"<<endl;
  cin >> birthmonth;
  float months_in_seconds = ((birthmonth+caryover_days)-day)*((365.25/12)*86400);
  if (months_in_seconds < 0)
  {
                        caryover_months = 1;
                        months_in_seconds = 31557600 + months_in_seconds;
  }
  cout<< "Enter your birth year"<<endl;
  cin >> birthyear;
  float years_in_seconds = (year-birthyear)*31557600;
  float age_in_seconds = years_in_seconds + months_in_seconds + days_in_seconds + hours_in_seconds + minutes_in_seconds + seconds_after_hour;
  cout << "You are " << age_in_seconds << " seconds old" << endl;
  float age_in_minutes = age_in_seconds/60;
  cout << "You are " << age_in_minutes << " minutes old" << endl;
  float age_in_hours = age_in_minutes/60;
  cout << "You are " << age_in_hours << " hours old" << endl;
  float age_in_days = age_in_hours/24;
  cout << "You are " << age_in_days << " days old" << endl;
  float age_in_months = (age_in_days/(365.25/12));
  cout << "You are " << age_in_months << " months old" << endl;
  float age_in_years = age_in_months/365.25;
  cout << "You are " << age_in_years << " years old" << endl;
  cout << "You are " << years_in_seconds/31557600 << " years, " << months_in_seconds/((365.25/12)*86400) << " months, " << days_in_seconds/86400 << " days, " << hours_in_seconds/3600 << " hours, " << minutes_in_seconds/60 << " minutes, and " << seconds_after_hour << " seconds old" << endl;
  return 0;
  }

